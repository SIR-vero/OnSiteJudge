<?php
include "config_admin.php";
include "check_token_admin.php";  // Check user token

// Check user login or not
if(!isset($_SESSION['username'])){
 header('Location: index.php');
}

// logout
if(isset($_POST['but_logout'])){
 session_destroy();
 header('Location: index.php');
}
?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	$re = mysqli_fetch_array(mysqli_query($con,"SELECT * FROM contest"));
	$quest = $re['questions'];
	
}
?>


<form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
</form>