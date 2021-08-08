<html>

<head>

<title>MyJudge</title>
<link rel="stylesheet" href="css/indexcss.css">
</head>

<body>

<button class = "admin" onclick="document.location='admin/index.php'">ADMIN LOGIN</button>

<div>
<h1 class = "AdminLogin">
	WELCOME TO USER LOGIN
</h1>
</div>

 <form class="box" method="post" action="checkLoginGentoken.php">

   <h1>Login</h1>

    <input type="text" class="textbox" id="txt_uname" name="txt_uname" placeholder="Username" />

    <input type="password" class="textbox" id="txt_uname" name="txt_pwd" placeholder="Password"/>

    <input type="submit" value="Login" name="but_submit" id="but_submit" />


 </form>


</body>

</html>