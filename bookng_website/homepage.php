<?php
	include("connMysql.php");
	
	if (!@mysqli_select_db($db_link, "whattoeat")) die("資料庫選擇失敗！");
    session_start();
	
	if (isset($_SESSION['aNo'])) {
		$sql_query = "SELECT * FROM `account` WHERE `aNo`= '".$_SESSION["aNo"]."'";
		$result = mysqli_query($db_link, $sql_query);
		$user = mysqli_fetch_array($result, MYSQLI_ASSOC);
	} else {
		$user = NULL;
	}
?>

<!DOCTYPE html>
<html lang="zh-Hant-TW">
  <head>
    <meta charset ="UTF-8">
	<title>What to EAT</title>
	<link rel="stylesheet" href="css/reset.css">
	<link rel="stylesheet" href="css/style.css">
	<link rel="stylesheet" href="css/system.css">
	<script src="https://kit.fontawesome.com/e7378d5906.js" crossorigin="anonymous"></script>
	
  </head>
  <body>
    <header class="header">
	  <h1 class="logo">
	    <a href="homepage.php">What to EAT</a>
	  </h1>
	  <nav class="global-nav">
	    <ul>
		  <!--會員登入時介面-->
		<?php 
		if($user){
		  if($user['category'] == 'M'){ ?>	  
		  <li class="nav-item active"><a href="#">HOME</a></li>
		  <li class="nav-item"><a href="calendar.php">CALENDAR</a></li>
		  <li class="nav-item"><a href="#jumpToRestaurant">RESTAURANTS</a></li>
		  <li class="nav-item"><a href="favorites.php">FAVORITES</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>

		  <!--餐廳管理員登入時介面-->		
		  <?php }
		  else if($user['category'] == 'R') { ?>
		  <li class="nav-item active"><a href="#">HOME</a></li>
		  <li class="nav-item"><a href="#jumpToUpdate">UPDATE</a></li>
		  <li class="nav-item"><a href="reservation_information.php">RESERVATION</a></li>
		  <li class="nav-item"><a href="reservation_meal.php">RESERVATION MEAL</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>
		  

		  <!--系統管理員登入時介面-->		
		  <?php }
		  else if($user['category'] == 'S') { ?>
		  <li class="nav-item active"><a href="#">HOME</a></li>
		  <li class="nav-item"><a href="#jumpToManage">MANAGE</a></li>
		  <li class="nav-item"><a href="創建餐廳帳號.php">CREAT ACCT</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>

		  <!--訪客介面-->
		  <?php }}
		  if($user == NULL) {
		  ?> 
		  <li class="nav-item active"><a href="#">HOME</a></li>
		  <li class="nav-item"><a href="#jumpToRestaurant">RESTAURANTS</a></li>
		  <li class="nav-item"><a href="會員登入.php">LOG IN</a></li> 
		  <?php 
		  } 
		  ?>

		</ul>
	  </nav>
	</header>
	
	<div class="wrapper clearfix">
	<main class="main">
	    <section>
	      <h2 class="hidden">HOT TOPIC</h2>
		  <a href="#" class="hot-topic clearfix">
		    <img class="image" src="./images/butter.jpeg" alt="程式撰寫畫面">
			<div class="content">
			  <h3 class="title">吃甚麼?</h3>
			  <p class="desc">希望透過餐廳預約系統的整合，讓會員可以從網站尋找感興趣的美食，並進行預約餐廳，省去另外尋找預約網站或是撥打電話的困擾!</p>
			  <time class="date" datetime="2021-04-01">2021.05.01 SAT</time>
			</div>
		  </a>
		  <!-- 置入HOT TOPIC內容 -->
		</section>

		<h2 class="heading">NEWS</h2>
		<ul class="scroll-list">
		  <li class="scroll-item">
		    <a href="#">
			  <time class="date" datetime="2021-04-01">2021.04.01 FRI</time>
			  <span class="category news">NEWS</span>
			  <span class="title">瀏覽我們最新上架的餐廳!</span>
			</a>
		  </li>
		  <li class="scroll-item">
		    <a href="#">
			  <time class="date" datetime="2021-04-22">2021.04.22 SAT</time>
			  <span class="category">TOPIC</span>
			  <span class="title">炎炎夏日就是要吃飽飽!</span>
			</a>
		  </li>
		</ul>


	<?php 
	// 系統管理員頁面
	if($user != NULL && $user['category'] == 'S') {
		$result1 = mysqli_query($db_link, "SELECT * FROM account NATURAL JOIN restaurant WHERE category = 'R'");
		if(mysqli_num_rows($result1) > 0) {
			$per = 10; //每頁有幾筆資料 
    		$current_page = 1; //預設頁數
	
    		//若已經有翻頁，將頁數更新
    		if (isset($_GET['page'])) {
    	  	$current_page = $_GET['page'];
    		}
    		//本頁開始記錄筆數 = (頁數-1)*每頁記錄筆數
    		$startRecord = ($current_page - 1) * $per;
    		//未加限制顯示筆數的SQL敘述句
    		$sql = "SELECT * FROM account NATURAL JOIN restaurant WHERE category = 'R'";
    		//加上限制顯示筆數的SQL敘述句，由本頁開始記錄筆數開始，每頁顯示預設筆數
    		$sql_limit = $sql." LIMIT ".$startRecord.", ".$per;
    		//以加上限制顯示筆數的SQL敘述句查詢資料到 $result 中
    		$result1 = mysqli_query($db_link, $sql_limit);
    		//以未加上限制顯示筆數的SQL敘述句查詢資料到 $all_result 中
    		$all_result = mysqli_query($db_link, $sql);
    		//計算總筆數
    		$total_records = mysqli_num_rows($all_result);
    		//計算總頁數=(總筆數/每頁筆數)後無條件進位。
    		$total_pages = ceil($total_records/$per);
	?>

	<div class="restAccount" id="jumpToManage">
    <table>
        <tr>
            <th>餐聽帳號編碼</th>
            <th>密碼</th>
            <th>帳號種類</th>
            <th>經營餐廳名稱</th>
            <th>執行動作</th>
        </tr>
        <?php
            $i = 0;
            while($row1 = mysqli_fetch_array($result1)) { ?>
        <tr>
            <td><?php echo $row1["aNo"]; ?></td>
            <td><?php echo $row1["password"]; ?></td>
            <td><?php echo $row1["category"]; ?></td>
            <td><?php echo $row1["rName"]; ?></td>
            <td><a href="./deleteRest.php?rId=<?php echo $row1['rId']; ?>&aNo=<?php echo $row1['aNo']; ?>&rName=<?php echo $row1['rName']; ?>">刪除</a></td>
        </tr>

        <?php $i++; }?>
    </table>
	</div><br>
	
	<?php
	if ($current_page > 1) { // 若不是第一頁則顯示 ?>
		<td><a href="homepage.php?page=1#jumpToManage">第一頁</a></td>
    	<td><a href="homepage.php?page=<?php echo $current_page-1;?>#jumpToManage">上一頁</a></td>
	<?php } 

		for($j = 1; $j <= $total_pages; $j++){
        	if($j == $current_page) {
            	echo $j." ";
        	}else {
            	echo "<a href=\"homepage.php?page=$j#jumpToManage\">$j</a> ";
        	}
    	}
    	if ($current_page < $total_pages) { // 若不是最後一頁則顯示 ?>
    		<td><a href="homepage.php?page=<?php echo $current_page+1;?>#jumpToManage">下一頁</a></td>
    		<td><a href="homepage.php?page=<?php echo $total_pages;?>#jumpToManage">最後頁</a></td>
    <?php }
	}else {
        echo 'No result found';
	}

	// 餐廳管理員頁面
	}else if($user != NULL && $user['category'] == 'R') { 
		$sql = "SELECT rId FROM account WHERE aNo='".$_SESSION["aNo"]."'";
		$result = mysqli_query($db_link, $sql);
		$row = mysqli_fetch_array($result);
		$rId = $row['rId'];

		$sql = "SELECT * FROM restaurant WHERE rId = $rId";
    	$result = mysqli_query($db_link, $sql);
		if(mysqli_num_rows($result) > 0) {
		$i = 0;
    	while($row = mysqli_fetch_array($result)) { ?>

		<section class="articles">
		  	<h2 class="hidden">ARTICLES</h2>
		  	<div class="clearfix" id="jumpToUpdate">
			  	<a href="restaurant.php?rId=<?php echo $row["rId"]; ?>" class="article-box">
					<?php echo '<img src="data:image/jpeg;base64,'.base64_encode( $row['photo'] ).'"/ class="image">'; ?>
			  		<h3 class="title"><?php echo $row["rName"]; ?></h3>
			  		<p class="desc"><?php echo $row["rPhone"]; ?></p>
			  		<p class="title">更新餐廳資訊</p>
					<time class="date" datetime="2021-04-23">均消: <?php echo $row["bottomPrice"]; ?></time>
				</a>
			</div>
		</section> 
		<?php } $i++;
	}
	
	// 會員跟訪客頁面
	}else {?>

	<?php
		$per = 8; //每頁有幾筆資料 
    	$current_page = 1; //預設頁數
	
    	//若已經有翻頁，將頁數更新
    	if (isset($_GET['page'])) {
    	  $current_page = $_GET['page'];
		  $_SESSION['page'] = $current_page;
    	}
    	//本頁開始記錄筆數 = (頁數-1)*每頁記錄筆數
    	$startRecord = ($current_page - 1) * $per;
    	//未加限制顯示筆數的SQL敘述句
    	$sql = "SELECT * FROM restaurant";
    	//加上限制顯示筆數的SQL敘述句，由本頁開始記錄筆數開始，每頁顯示預設筆數
    	$sql_limit = $sql." LIMIT ".$startRecord.", ".$per;
    	//以加上限制顯示筆數的SQL敘述句查詢資料到 $result 中
    	$result = mysqli_query($db_link, $sql_limit);
    	//以未加上限制顯示筆數的SQL敘述句查詢資料到 $all_result 中
    	$all_result = mysqli_query($db_link, $sql);
    	//計算總筆數
    	$total_records = mysqli_num_rows($all_result);
    	//計算總頁數=(總筆數/每頁筆數)後無條件進位。
    	$total_pages = ceil($total_records/$per);
	?>

	<h2 class="heading" id="jumpToRestaurant">RESTAURANTS</h2><br>
	<div class="article-frame">
	<?php 
	if(mysqli_num_rows($result) > 0) {
	$i = 0;
    while($row = mysqli_fetch_array($result)) { 

		// 會員或訪客不會看到未籌備好的餐廳
		if($row["rName"] != 'None') {?>
		<section class="articles">
		  	<h2 class="hidden">ARTICLES</h2>
		  	<div class="clearfix">
				<a href="restaurant.php?rId=<?php echo $row['rId']; ?>" class="article-box" id="block<?php echo $row['rId'] ?>" target="_parent">
				
					<?php echo '<img src="data:image/jpeg;base64,'.base64_encode( $row['photo'] ).'"/ class="image">'; ?>
			  		<h3 class="title"><?php echo $row["rName"]; ?></h3>
			  		<p class="desc"><?php echo $row["rPhone"]; ?></p>
			  		<p class="desc"><?php echo $row["rAddress"]; ?></p>
					
					<time class="date" datetime="2021-04-23">均消: <?php echo $row["bottomPrice"]; ?></time>
				</a>

				<?php if($user != NULL && $user['category'] == 'M') { // 會員才能加我的最愛?>

				<!-- heart button -->
				<div class="heart-btn">
					<div class="heartContent">
					<?php
						// 檢查餐廳是否被該會員加進收藏
						$favResult = mysqli_query($db_link, "SELECT * FROM favorites WHERE aNo='".$_SESSION["aNo"]."' AND rId = '".$row["rId"]."'"); 
						if(mysqli_num_rows($favResult) > 0) { ?>
							<i id="icon<?php echo $row['rId'];?>" onclick="change('icon<?php echo $row['rId'];?>')" class="fas fa-heart" aria hidden="true"></i>
						<?php 
						}else { ?>
							<i id="icon<?php echo $row['rId'];?>" onclick="change('icon<?php echo $row['rId'];?>')" class="far fa-heart" aria hidden="true"></i>
						<?php } ?>
						
					</div>
				</div>
				<?php }?>

			</div>
		</section> 
		<?php }
	}  $i++; }?>
	</div>

	<?php
	if ($current_page > 1) { // 若不是第一頁則顯示 ?>
		<td><a href="homepage.php?page=1#jumpToRestaurant">第一頁</a></td>
    	<td><a href="homepage.php?page=<?php echo $current_page-1;?>#jumpToRestaurant">上一頁</a></td> 
	<?php } 

	for($j = 1; $j <= $total_pages; $j++){
        if($j == $current_page){
            echo $j." ";
        }else{
            echo "<a href=\"homepage.php?page=$j#jumpToRestaurant\">$j</a> ";
        }
    }
    if ($current_page < $total_pages) { // 若不是最後一頁則顯示 ?>
    	<td><a href="homepage.php?page=<?php echo $current_page+1;?>#jumpToRestaurant">下一頁</a></td>
    	<td><a href="homepage.php?page=<?php echo $total_pages;?>#jumpToRestaurant">最後頁</a></td>
    <?php } }?>
	</main>

	<div class="sidemenu">
		
	<?php
	if(!$user) { ?>
		<h2 class="hidden">SEARCH</h2>
		<form class="search-box" action="search.php" method="get">
		  <input class="search-input" type="text" name="keyword" placeholder="SEARCH">
		 <input class="search-button" type="submit" value="搜尋">
		  <p class="text">搜尋餐廳名稱</p>
		</form>
	<?php
	}
	else {
		if($user['category'] != 'R') {?>
			<h2 class="hidden">SEARCH</h2>
			<form class="search-box" action="search.php" method="get">
				<input class="search-input" type="text" name="keyword" placeholder="SEARCH">
				<input name="search" type="hidden" value="search">
				<input class="search-button" type="submit" value="搜尋">
				<p class="text">搜尋餐廳名稱</p>
			</form>
	<?php }
	} ?>

		<br><br><h2 class="heading">RANKING</h2>
		<ol class="ranking">
			<li class="ranking-item">
			<?php 
			$result = mysqli_query($db_link, "SELECT * FROM `restaurant` ORDER BY rate DESC LIMIT 10");
			while($row = mysqli_fetch_array($result)) { ?>
			<a href="restaurant.php?rId=<?php echo $row['rId'];?>" target="_parent">
				<span class="order"></span>
				<h3 class="text"><?php echo $row['rName']?></h3><br>
				<div class="text-div">
					<p class="text"><?php echo $row['rDesc']?></p>
				</div>
			</a>
			<?php }?>
		</li>
	</ol>
	
	
	<!--修改餐廳地圖連結-->
	<?php
	if($user) {			
		if($user['category'] == 'R') {?>
			<form class="search-box" action="updatemap.php" method="post">
				<input class="search-input" type="text" name="updatemap" placeholder="UPDATE GOOGLE MAP">
				<input class="search-button" type="submit" value="更新">
				<p class="text">更新餐廳地圖連結</p>
			</form>
			<form class="search-box" action="updatecreditScore.php" method="post">
				<input class="search-input" type="text" name="updatecreditScore" placeholder="UPDATE RESERVATION CREDIT SCORE">
				<input class="search-button" type="submit" value="更新">
				<p class="text">更新預約餐廳的信用分數下限</p>
			</form>
			<form class="search-box" action="updatecancelDay.php" method="post">
				<input class="search-input" type="text" name="cancelDay" placeholder="UPDATE CANCELLATION DEADLINE">
				<input class="search-button" type="submit" value="更新">
				<p class="text">更新取消預約的天數</p>
			</form>
	<?php
		}
	}
	?>
	</div>
	</div>
	
	<footer class="footer">
	  <ul class="horizontal-list">
	    <li class="horizontal-item"><a href="#">ABOUT ME</a></li>
		<li class="horizontal-item"><a href="#">SITE MAP</a></li>
		<li class="horizontal-item"><a href="#">SNS</a></li>
		<li class="horizontal-item"><a href="#">CONTACT</a></li>
	  </ul>
	<p class="copyright">Copyright © 2021What To EAT</p>
	</footer>
  </body>

	<script>
	<?php ?>
		function change(iconID) {
            if (document.getElementById(iconID).className == "far fa-heart") {
                document.getElementById(iconID).className = "fas fa-heart";
				var x = iconID.split("n")
				window.location="addFav.php?rId="+x[1]+"&option=add";
				
            }else {
                document.getElementById(iconID).className = "far fa-heart";
				var x = iconID.split("n")
				window.location="addFav.php?rId="+x[1]+"&option=remove";
            }
        }
	</script>

</html>