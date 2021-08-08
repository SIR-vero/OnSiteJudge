<html>

<head>

<title>ADMIN LOGIN</title>
<link rel="stylesheet" href="../css/indexcssAdmin.css">
</head>

<body>

<button onclick="document.location='../index.html'">USER LOGIN</button>

<div>
<h1 class = "AdminLogin">
	WELCOME TO ADMIN LOGIN
</h1>
</div>

 <form class="box" method="post" action="checkLoginGentoken_admin.php">

   <h1>Login</h1>

    <input type="text" class="textbox" id="txt_uname" name="txt_uname" placeholder="Username" />

    <input type="password" class="textbox" id="txt_uname" name="txt_pwd" placeholder="Password"/>

    <input type="submit" value="Login" name="but_submit" id="but_submit" />


 </form>


</body>

</html>