<?php
    session_start();
    include("connection1.php"); // connect to the db first
    if (!@mysqli_select_db($db_link, "webfp")) die("資料庫選擇失敗！");
    
    // if the user clicked 'sign in',
    // check whether his/her name and password are correct or not
    if(isset($_POST["action"]) && ($_POST["action"] == "signIn") && ($_POST["name"] != "")) {
        $name=$_POST["name"];
        $password=$_POST["password"];
        
        // find the corresponding name and its password from the db
        $sql = "SELECT members.password FROM `members` WHERE members.name='$name'";
        $result=mysqli_query($db_link, $sql);
        $row=mysqli_fetch_assoc($result);

        if($password == $row['password']) {
            $_SESSION["name"] = $name;
            
            // set a time stamp
            $_SESSION["login_time_stamp"] = time();

            // switch the acount
            if($name == "misuser") {
                mysqli_close($db_link);
                include("connection2.php"); // connect to the db first
                if (!@mysqli_select_db($db_link, "webfp")) die("資料庫選擇失敗！");
            }
            echo "<script language='javascript'>";
            echo "alert('登入成功!')";
            echo "</script>";
            echo "<script language='javascript'>";
            echo "</script>";
        
        }else {
            echo "<script language='javascript'>";
            echo "alert('請輸入正確帳號或密碼!')";
            echo "</script>";
            echo "<script language='javascript'>";
            echo "location.href='signIn.php'"; // back to the sign in page
            echo "</script>";
        }

    // user didn't enter anything
    }else if(isset($_POST["action"]) && ($_POST["action"] == "signIn") && ($_POST["name"] == "")) {
        echo "<script language='javascript'>";
        echo "alert('請輸入正確帳號或密碼!')";
        echo "</script>";
        echo "<script language='javascript'>";
        echo "location.href='signIn.php'"; // back to the sign in page
        echo "</script>";
    }    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="./signIn.css">

    <style>
    /* .memberInfo {
        display: flex;
        justify-content: center;
        align-items: center;
        text-align: center;
        height: 30%;
        width: 88vw;
        color: steelblue;
    }
    .memberTd {
        width: 22vw;
        font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;
    } */
    </style>
</head>
<body>
    
    <header><h1>會員資料</h1><header><br><br>
            
    <table class="memberInfo">
    <?php
        // after 30 min, ser will sign out automatically
        if(time()-$_SESSION["login_time_stamp"] > 1800) { 
            session_unset(); 
            session_destroy(); 
            header("Location:signIn.php"); 
        }

        // the user has signed in successfully, print the member infomation
        if(isset($_SESSION["name"]) && $_SESSION["name"] != "") {
            $name = $_SESSION["name"];
            $seldb = @mysqli_select_db($db_link, "webfp");
            if (!$seldb) die("資料庫選擇失敗！");

            $sql = "SELECT * FROM members WHERE members.name = '$name'";
            $result = mysqli_query($db_link, $sql);

        }
        while($row_result = mysqli_fetch_assoc($result)){
            echo "<tr>";
            echo "<th class='memberTd'>會員編號</th>";
            echo "<th class='memberTd'>姓名</th>";
            echo "<th class='memberTd'>手機</th>";
            echo "<th class='memberTd'>會員點數</th>";
            echo "<tr>";
            echo "<td class='memberTd'>".$row_result["member_id"]."</td>";
            echo "<td class='memberTd'>".$row_result["name"]."</td>";
            echo "<td class='memberTd'>".$row_result["phone"]."</td>";
            echo "<td class='memberTd'>".$row_result["points"]."</td>";
            echo "</tr>";
        }
    ?>
    </table>

    <!-- upload photo -->
        <?php
            // include("connection1.php");
            // $seldb = @mysqli_select_db($db_link, "webfp");
            $sql = "SELECT * FROM photos";
            $result = mysqli_query($db_link, $sql);
            while($row_result = mysqli_fetch_array($result)) {
                echo "<div>";
                echo "<img src='images/member_photos/".$row_result['member_photo']."'>";
                echo "<p>".$row_result['text']."</p>";
                echo "</div>";
            }
        ?>

        

    <section>
        <!-- sign out button -->
        <form action="./signIn.php" method="post">
                <input name="action" type="hidden" value="signOut">
                <button type="submit" name="submit">登出</button>
        </form>
        <form action="./photo.php" method="post">
                <input name="action" type="hidden" value="signOut">
                <button type="submit" name="submit" class="photoButton">上傳照片</button>
        </form>
    </section>
</body>
</html>
	
	

