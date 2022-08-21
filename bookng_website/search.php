<?php
	include 'connMysql.php';
    if (!@mysqli_select_db($db_link, "whattoeat")) die("資料庫選擇失敗！");
    
	session_start();
	if (isset($_SESSION['aNo'])) {
		$sql_query = "SELECT * FROM `account` WHERE `aNo`= '".$_SESSION["aNo"]."'";
		$loginResult = mysqli_query($db_link, $sql_query);
		$user = mysqli_fetch_array($loginResult, MYSQLI_ASSOC);
	} else {
		$user = NULL;
	}
?>

<!DOCTYPE html>
<html lang="zh-Hant-TW">
<head>
    <meta charset ="UTF-8">
	<title></title>
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
		  <?php if($user){
				if($user['category'] == 'M'){ ?>	  
		  <li class="nav-item active"><a href="homepage.php">HOME</a></li>
		  <li class="nav-item"><a href="calendar.php">CALENDAR</a></li>
		  <li class="nav-item"><a href="homepage.php#jumpToRestaurant">RESTAURANTS</a></li>
		  <li class="nav-item"><a href="favorites.php">FAVORITES</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>

		  <!--餐廳管理員登入時介面-->		
		  <?php }
		  else if($user['category'] == 'R') { ?>
		  <li class="nav-item active"><a href="homepage.php">HOME</a></li>
		  <li class="nav-item"><a href="homepage.php#jumpToUpdate">UPDATE</a></li>
		  <li class="nav-item"><a href="reservation_information.php">RESERVATION</a></li>
		  <li class="nav-item"><a href="reservation_meal.php">RESERVATION MEAL</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>
		  

		  <!--系統管理員登入時介面-->		
		  <?php }
		  else if($user['category'] == 'S') { ?>
		  <li class="nav-item active"><a href="homepage.php">HOME</a></li>
		  <li class="nav-item"><a href="homepage.php#jumpToManage">MANAGE</a></li>
		  <li class="nav-item"><a href="創建餐廳帳號.php">CREAT ACCT</a></li>
		  <li class="nav-item"><a href="logout.php">LOG OUT</a></li>

		  <!--訪客介面-->
		  <?php }}
		  if($user == NULL) {
		  ?> 
		  <li class="nav-item active"><a href="homepage.php">HOME</a></li>
		  <li class="nav-item"><a href="homepage.php#jumpToRestaurant">RESTAURANTS</a></li>
		  <li class="nav-item"><a href="會員登入.php">LOG IN</a></li> 
		  <?php 
		  } 
		  ?>

		</ul>
	  </nav>
	</header>
	
	<div class="wrapper clearfix">
	<main class="main">
	<?php 
	if(isset($_GET["keyword"])) {
		$keyword = $_GET['keyword'];
		$_SESSION['keyword'] = $_GET['keyword'];

		if($user != NULL && $user['category'] == 'S') { // 系統管理員
        	$result1 = mysqli_query($db_link, "SELECT * FROM account NATURAL JOIN restaurant WHERE category = 'R' AND rName LIKE '%$keyword%'");
			$rownum = mysqli_num_rows($result1);?>

			<h2 class="heading">搜尋"<?php echo $keyword; ?>"得到<?php echo $rownum; ?>筆結果</h2><br>
		<?php 
		if(mysqli_num_rows($result1) > 0) {?>
		<div class="restAccount" id="jumpToManage">
    	<table>
        	<tr>
        	    <td>餐聽帳號編碼</td>
        	    <td>密碼</td>
        	    <td>帳號種類</td>
        	    <td>經營餐廳名稱</td>
        	    <td>執行動作</td>
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
		</div>
	
    <?php
	}}else { // 會員
	    $result = mysqli_query($db_link, "SELECT * FROM restaurant WHERE rName LIKE '%$keyword%'"); ?>
	    
		<?php $rownum = mysqli_num_rows($result);?>
		<h2 class="heading">RESTAURANTS</h2><br>
		<h2 class="heading">搜尋"<?php echo $keyword; ?>"得到<?php echo $rownum; ?>筆結果</h2><br>

		<div class="article-frame">
			<?php 
			if(mysqli_num_rows($result) > 0) {
				$i = 0;
            	while($row = mysqli_fetch_array($result)) {
            ?>
		    <section class="articles">
		      	<h2 class="hidden">ARTICLES</h2>
		      	<div class="clearfix">
		    		<a href="restaurant.php?rId=<?php echo $row["rId"]; ?>" class="article-box" target="_parent">
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
		    <?php } $i++; }?>
		</div>
	<?php }?>
	</main>
	<?php }?>

	<div class="sidemenu">
		<h2 class="hidden">SEARCH</h2>
		<form class="search-box" action="search.php" method="get">
		  <input class="search-input" type="text" name="keyword" placeholder="SEARCH">
		 <input class="search-button" type="submit" value="搜尋">
		  <p class="text">搜尋餐廳名稱</p>
		</form>

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
				window.location="addFav.php?rId="+x[1]+"&option=addFromSearch";
            }else {
                document.getElementById(iconID).className = "far fa-heart";
				var x = iconID.split("n")
				window.location="addFav.php?rId="+x[1]+"&option=removeFromSearch";
            }
        }
	</script>
</html>