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
  
  <h1>WELCOME <?php echo $_SESSION['username'] ?> </h1></br>
  <?php
	$contest = mysqli_query($con, "SELECT * FROM contest");
	$contestRow = mysqli_fetch_array($contest);
	if ($contestRow['active'] == 1)
	{
		echo "<h2>".$contestRow['contest_name']." is live </h2></br>";
		echo "<form method=\"post\" action=\"takesubmissions.php\">
				<label for=\"language\"> Language : </label>
				<select id=\"language\" name=\"language\">
					<option value=\"1\"> C </option>
					<option value=\"2\"> CPP14 </option>
					<option value=\"3\"> JAVA </option>
					<option value=\"4\"> PYTHON3 </option>
				</select>
				
				<label for=\"question\"> Question : </label>
				<select id=\"question\" name=\"question\">";
				for ($x = 1; $x <= $contestRow['questions']; $x++)
				{
					echo "<option value=\"$x\"> $x </option>";
				}
					
				echo "</select>
				<br>
				<label for=\"code\"> Paste your code : </label><br>
				<textarea id=\"code\" name=\"code\" rows=\"20\" cols=\"100\" style=\"overflow:scroll;\"></textarea>
				<br>
				
				<input type=\"submit\" value=\"Submit\" name=\"code_submit\">
			  </form>
				";
	}
	
	else
	{
		echo "<h2>".$contestRow['contest_name']." is not live </h2></br>";
	}
  ?>
  
  <form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
  </form>
 </body>
</html>