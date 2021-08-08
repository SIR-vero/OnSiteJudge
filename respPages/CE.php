<?php
include "../config.php";

if (isset($_SESSION['username'])) {
  $result = mysqli_query($con, "SELECT token FROM user_token where username='".$_SESSION['username']."'");
 
  if (mysqli_num_rows($result) > 0) {
 
   $row = mysqli_fetch_array($result); 
   $token = $row['token']; 

   if($_SESSION['token'] != $token){
    session_destroy();
    //header('Location: ../index.php');
	echo "wrong token";
   }
  }
}  // Check user token

// Check user login or not
if(!isset($_SESSION['username'])){
 //header('Location: ../index.php');
 echo "no username";
}

$runid = mysqli_real_escape_string($con, $_SESSION["runid"]);
$updateQ = "UPDATE submissions SET status = 3 where run_id = ".$runid;
if(mysqli_query($con, $updateQ))
{
	echo "compilation Error";
}
else 
{
	echo "<h2><br>Couldn't record contact admin</h2></br>";
}
?>

<html>
<button class = "" onclick="document.location='../submissions.php'">Back To submissions</button>
</html>
