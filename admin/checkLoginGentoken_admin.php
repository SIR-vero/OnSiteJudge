<?php
include "config_admin.php";

if(isset($_POST['but_submit'])){

 $uname = mysqli_real_escape_string($con,$_POST['txt_uname']);
 $password = mysqli_real_escape_string($con,$_POST['txt_pwd']);

 if ($uname != "" && $password != ""){

  $sql_query = "select * from admin where username='".$uname."' and passcode='".$password."'";
  $result = mysqli_query($con,$sql_query);
  $row = mysqli_fetch_array($result);

  //$count = $row['cntUser'];

  if($row["username"] == $_POST["txt_uname"] && $row["passcode"] == $_POST["txt_pwd"]){
   $token = getToken(10);
   $_SESSION['username'] = $uname;
   $_SESSION['token'] = $token;

   // Update user token 
   $result_token = mysqli_query($con, "select count(*) as allcount from admin_token");
   $row_token = mysqli_fetch_assoc($result_token);
   if($row_token['allcount'] > 0){
    mysqli_query($con,"update admin_token set token='".$token."' where username='".$uname."'");
   }
   else{
    mysqli_query($con,"insert into admin_token(username,token) values('".$uname."','".$token."')");
   }
   header('Location: home_admin.php');
  }
  else{
   echo "Invalid username and password";
  }

 }

}

// Generate token
function getToken($length){
 $token = "";
 $codeAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 $codeAlphabet.= "abcdefghijklmnopqrstuvwxyz";
 $codeAlphabet.= "0123456789";
 $max = strlen($codeAlphabet); // edited

 for ($i=0; $i < $length; $i++) {
  $token .= $codeAlphabet[random_int(0, $max-1)];
 }

 return $token;
}