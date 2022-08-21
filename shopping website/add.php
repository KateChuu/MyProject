<?php 
session_start();
$member_id = $_SESSION["member_id"];
//echo "$member_id";

if(isset($_POST["action"]) && ($_POST["action"] == "add")) {
    include("connection1.php");
    if (!@mysqli_select_db($db_link, "webfp")) die("資料庫選擇失敗！");
    
    // check whether the product user entered exist or not
    $product_name = $_POST["product_name"];
    $amount = $_POST["amount"];
    $total_price = $_POST["total_price"];
    $sql = "SELECT product_name FROM `products` WHERE product_name = '$product_name'";
    $result = mysqli_query($db_link, $sql) or trigger_error("Query: $sql\ n
    MySQL Error: " . mysqli_error($db_link));

    if(mysqli_num_rows($result)) {
        // we do have the product
        // then check the total_price is correct or not
        $sql = "SELECT price FROM `products` WHERE product_name = '$product_name'";
        $result = mysqli_query($db_link, $sql);
        $row = mysqli_fetch_assoc($result);
        $unit_price = $row['price'];
        $temp = $unit_price * $amount;

        if($total_price == $temp) {
            
            $sql = "INSERT INTO `orders` (`member_id` ,`product_name` ,`amount` ,`total_price`) VALUES ('$member_id', '$product_name', '$amount', '$total_price')";
            mysqli_query($db_link, $sql);

            echo "<script language='javascript'>";
            echo "alert('新增商品成功!')";
            echo "</script>";
        }else {
            echo "<script language='javascript'>";
            echo "alert('請輸入正確數量或總價!')";
            echo "</script>";
        }

    }else {
        echo "<script language='javascript'>";
        echo "alert('查無此商品!')";
        echo "</script>";
    }
}	
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>新增商品</title>
    <link rel="stylesheet" href="./signIn.css">
    <script src="https://kit.fontawesome.com/e7378d5906.js" crossorigin="anonymous"></script> 
</head>

<body>
    <header><h1>我的購物車</h1></header><br>
    <section>
        <form action="add.php" method="post">
            商品名稱 <br><input type="text" name="product_name"><br><br>
            數量 <br><input type="number" name="amount"><br><br>
            總價 <br><input type="text" name="total_price"><br><br>

            <input name="action" type="hidden" value="add">
            <button type="submit" name="submit" class="button">新增</button>
            </td>
        </form>
    </section>
</body>
</html>