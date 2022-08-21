<?php
    include("connMysql.php");
    if (!@mysqli_select_db($db_link, "whattoeat")) die("資料庫選擇失敗！");
    session_start();

    if (isset($_SESSION['aNo'])) {
        // 檢查會員是否有登錄
		$sql_query = "SELECT * FROM `account` WHERE `aNo`= '".$_SESSION["aNo"]."'";
		$loginResult = mysqli_query($db_link, $sql_query);
		$user = mysqli_fetch_array($loginResult, MYSQLI_ASSOC);

        if(isset($_SESSION['rId'])) {
            $text = $_POST["text"];
            //echo $text;

            // 檢查會員是否評論過這家餐廳
            $sql = "SELECT * FROM `comments` WHERE rId = '" . $_SESSION['rId'] . "' AND aNo = '" . $_SESSION['aNo'] . "'";
            $result = mysqli_query($db_link, $sql);

            if(mysqli_num_rows($result) > 0) { // 評過了，修改評論
                $sql = "UPDATE `comments` SET `text` = '$text' WHERE rId = '" . $_SESSION['rId'] . "' AND aNo = '" . $_SESSION['aNo'] . "'";

                if (mysqli_query($db_link, $sql)) {
                    echo "<script>alert('修改評論成功!')</script>";
                    echo '<meta http-equiv="refresh" content="0; url=restaurant.php?rId=';
                    echo $_SESSION['rId'];
                    echo  '">';
                }else {
                    echo "Error: " . $sql . "<br>" . mysqli_error($db_link);
                }
            }else {// 沒評過，新增評論
                $sql = "INSERT INTO `comments`(aNo, `text`, rId) VALUES ('" . $_SESSION['aNo'] . "', '$text', " . $_SESSION['rId'] . ")";
                if (mysqli_query($db_link, $sql)) {
                    echo "<script>alert('新增評論成功!')</script>";
                    echo '<meta http-equiv="refresh" content="0; url=restaurant.php?rId=';
                    echo $_SESSION['rId'];
                    echo  '">';
                }else {
                    echo "Error: " . $sql . "<br>" . mysqli_error($db_link);
                }
            }

        }
    }
?>