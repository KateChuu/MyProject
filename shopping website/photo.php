<?php
    
    // if submit button is clicked
    if(isset($_POST["upload"]) && ($_POST["upload"] == "upload")) {
        // the path to store the upload photos
        $target = "images/member_photos/".basename($_FILES['image']['name']);

        // connect to the data base
        include("connection1.php");
        $seldb = @mysqli_select_db($db_link, "webfp");
        // get all the submitted data from the form
        $image = $_FILES['image']['name'];
        $text = $_POST['text'];
        $sql = "INSERT INTO `photos` VALUES (1, '$image', '$text')";
        mysqli_query($db_link, $sql); // store the submitted data into the db table

        if(move_uploaded_file($_FILES['image']['tmp_name'], $target)) {
            echo "<script language='javascript'>";
            echo "alert('上傳照片成功!')";
            echo "</script>";
            header("Location:signInBack.php");
        }else {
            echo "<script language='javascript'>";
            echo "alert('上傳照片失敗!')";
            echo "</script>";
        }

    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="./signIn.css">
</head>

<body>
    <form action="./photo.php" method="post" enctype="multipart/form-data">
            <input type="hidden" name="size" value="1000000">
            <div>
                <input type="file" name="image">
            </div>
            <div>
                <textarea name="text" id="" cols="40" rows="4" placeholder="Say something about you photo!"></textarea>
            </div>
            <div>
                <button type="submit" name="upload" value="upload">上傳</button>
            </div>
        </form>

</body>
</html>