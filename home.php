<?php
include "config.php";
include "check_token.php";  // Check user token

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
<!doctype html>
<html>
 <head></head>
 <body>
  
  <?php
	$sql_query = "SELECT COUNT(*) as cntCntst FROM contest";
	$result = mysqli_query($con, $sql_query);
	$row = mysqli_fetch_array($result);

	$count = $row['cntCntst'];

	if($count == 0)
	{
		echo "<h1>NO CONTEST CONFIGURED</h1>";
	}
	else
	{
		header('Location: submissions.php');
	}
  ?>
  
  <form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
  </form>
 </body>
</html>