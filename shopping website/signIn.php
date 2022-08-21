<?php
session_start();

// if the user clicked 'sign out', delete the session
if(isset($_POST["action"]) && ($_POST["action"]=="signOut")){
    unset($_SESSION["name"]);
}

// the user has signed in successfully, but click 'sign in' again
if(isset($_SESSION["name"]) && $_SESSION["name"] != ""){
	header("Location: signInBack.php");
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>會員登入</title>
    <link rel="stylesheet" href="./signIn.css">
    <script src="https://kit.fontawesome.com/e7378d5906.js" crossorigin="anonymous"></script>

</head>
<body>
    <header>
        <div><i class="fas fa-user-circle fa-5x"></i></div>
        <div><h1>會員登入</h1></div>
    </header>
    
    <section>
        <!-- form for signing in -->
        <form action="signInBack.php" method="post">
            用戶姓名 <input type="text" name="name"><br><br>
            帳號密碼 <input type="password" placeholder="password" name="password"><br><br>
            <input name="action" type="hidden" value="signIn">
            <button type="submit" name="submit">確認</button>
        </form>
    </section>
</body>
</html>