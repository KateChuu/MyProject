<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>我的購物車</title>
    <link rel="stylesheet" href="./shoppingCart.css">
    <script src="https://kit.fontawesome.com/e7378d5906.js" crossorigin="anonymous"></script> 
</head>
<body>
    <header>
        <h1>我的購物車</h1><br><br>
    </header>
    
    <div class="container">
        <table class="productInfo">
        <?php
            
        if(isset($_SESSION["name"]) && $_SESSION["name"] != "") {
            $name = $_SESSION["name"];
            include("connection1.php");
            $seldb = @mysqli_select_db($db_link, "webfp");
            if (!$seldb) die("資料庫選擇失敗！");

            // select the member_id of signed in member
            $sql = "SELECT members.member_id FROM `members` WHERE members.name = '$name'";
            $result = mysqli_query($db_link, $sql);
            while($row_result = mysqli_fetch_assoc($result)) {
                $_SESSION["member_id"] = $row_result["member_id"];
            }
            $member_id = $_SESSION["member_id"];
                
            // use member_id to select the orders
            $sql = "SELECT * FROM `orders` WHERE orders.member_id = '$member_id'";
            $result = mysqli_query($db_link, $sql);
            while($row_result = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<th class='productTd'>會員編號</th>";
                echo "<th class='productTd'>訂單編號</th>";
                echo "<th class='productTd'>產品名稱</th>";
                echo "<th class='productTd'>數量</th>";
                echo "<th class='productTd'>總價</th>";
                echo "<tr>";
                echo "<td class='productTd'>".$row_result["member_id"]."</td>";
                echo "<td class='productTd'>".$row_result["order_id"]."</td>";
                echo "<td class='productTd'>".$row_result["product_name"]."</td>";
                echo "<td class='productTd'>".$row_result["amount"]."</td>";
                echo "<td class='productTd'>".$row_result["total_price"]."</td>";
                // echo "<br>";
            }

        }else {
            echo "<script language='javascript'>";
            echo "alert('您尚未登入!')";
            echo "</script>";
        }
        ?>
        </table>
        <br><br><br>

        <div class="buttons">
            <div class="buttons">
            <div class="button">
                <a href="./add.php">新增商品 <i class="fas fa-cart-plus"></i></a>
            </div>
            <div class="button">
                <a href="./delete.php">刪除商品 <i class="fas fa-trash-alt"></i></a>
            </div>
        </div>
        </div>
        
    </div>
    
</body>
</html>