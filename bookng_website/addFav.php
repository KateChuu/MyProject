<?php
    include("connMysql.php");
    if (!@mysqli_select_db($db_link, "whattoeat")) die("資料庫選擇失敗！");
    session_start();

    if (isset($_SESSION['aNo'])) {
        // 檢查會員是否有登錄
		$sql_query = "SELECT * FROM `account` WHERE `aNo`= '".$_SESSION["aNo"]."'";
		$loginResult = mysqli_query($db_link, $sql_query);
		$user = mysqli_fetch_array($loginResult, MYSQLI_ASSOC);

        if($user) {
            $option = $_GET["option"];

            // 加進我的最愛
            if($option == 'add' || $option == 'addFromSearch' ) {
                $sql = "INSERT INTO `favorites` (aNo, rId) VALUES ('" . $_SESSION['aNo'] . "', " . $_GET["rId"] . ")";
            }else {
                $sql = "DELETE FROM `favorites` WHERE rId = '" . $_GET["rId"] . "' AND aNo = '" . $_SESSION['aNo'] . "'";
            }

            if (mysqli_query($db_link, $sql)) {
                
                if($option == 'add' || $option == 'remove') {
                    echo '<meta http-equiv="refresh" content="0; url=homepage.php?page=';
                    echo $_SESSION["page"];
                    echo '#block';
                    echo $_GET['rId'];
                    echo  '">';
                }else if($option == 'removeFromFav') { 
                    echo '<meta http-equiv="refresh" content="0; url=favorites.php">';
                }else { // $option == 'removeFromSearch' || $option == 'addFromSearch'
                    echo '<meta http-equiv="refresh" content="0; url=search.php?keyword=';
                    echo $_SESSION['keyword'];
                    echo  '">';
                }
                
            }else {
                echo "Error: " . $sql . "<br>" . mysqli_error($db_link);
            }
            mysqli_close($db_link);
        }

	} else {
        $user = NULL;
	}

?>