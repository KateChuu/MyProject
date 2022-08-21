<?php 
session_start();
$member_id = $_SESSION["member_id"];
//echo "$member_id";

if(isset($_POST["action"]) && ($_POST["action"] == "delete")) {
    include("connection1.php");
    if (!@mysqli_select_db($db_link, "webfp")) die("資料庫選擇失敗！");

    // check whether the order user want to delete exist or not
    $order_id = $_POST["order_id"];
    $sql = "SELECT * FROM `orders` WHERE orders.order_id = '$order_id' AND orders.member_id = '$member_id'";
    $result = mysqli_query($db_link, $sql) or trigger_error("Query: $sql\ n
    MySQL Error: " . mysqli_error($db_link));

    // if the order exist
    if (mysqli_num_rows($result)) {
        echo "<script language='javascript'>";
        echo "alert('刪除訂單成功!')";
        echo "</script>";
        $sql = "DELETE FROM `orders` WHERE order_id = '$order_id'";
	    mysqli_query($db_link, $sql);

    // if the order doesn't exist
    } else {
        echo "<script language='javascript'>";
        echo "alert('查無此訂單!')";
        echo "</script>";
    }
}	
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>刪除商品</title>
    <link rel="stylesheet" href="./signIn.css">
    <script src="https://kit.fontawesome.com/e7378d5906.js" crossorigin="anonymous"></script> 
</head>

<body>
    <header><h1>我的購物車</h1></header><br><br>
    <section>
        <form action="delete.php" method="post">
            請輸入欲刪除的訂單編號 <br><input type="number" name="order_id"><br><br>
            <input name="action" type="hidden" value="delete">
            <button type="submit" name="submit" class="button">刪除</button>
            </td>
        </form>
    </section>
</body>
</html>