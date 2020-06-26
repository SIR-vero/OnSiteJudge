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

<h1> Enter detail here </h1>

<?php
$re = mysqli_fetch_array(mysqli_query($con, "SELECT * FROM contest"));
for ($x = 1; $x <= $re['questions']; $x++)
{
	echo "enter the details of :".$x." question:</br>";
?>
	<form action="upload.php" method="post" enctype="multipart/form-data">
		Enter Question Name: 
		<input type="text" name="<?php echo $x;?>ques_name"></br>
		Short Name:
		<input type="text" name="<?php echo $x;?>short_ques_name"></br>
		Time Limit: </br>
		C and C++ :
		<select id="<?php echo $x;?>tlccpp" name="<?php echo $x;?>tlccpp">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
			<option value="8">8</option>
			<option value="9">9</option>
		</select></br>
		JAVA :
		<select id="<?php echo $x;?>tljava" name="<?php echo $x;?>tljava">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
			<option value="8">8</option>
			<option value="9">9</option>
		</select></br>
		Python :
		<select id="<?php echo $x;?>tlpyth" name="<?php echo $x;?>tlpyth">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
			<option value="8">8</option>
			<option value="9">9</option>
		</select></br>
		Points(1-10) :
		<select id="<?php echo $x;?>point" name="<?php echo $x;?>point">
			<option value="0">0</option>
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
			<option value="8">8</option>
			<option value="9">9</option>
			<option value="10">10</option>
		</select></br>
		Select input file :
		<input type="file" name="<?php echo $x;?>input_file"></br>
		Select output file :
		<input type="file" name="<?php echo $x;?>output_file"></br>
		
		
		</br></br>

<?php
}
?>
		<input type="submit" value="Done" name="second">
	</form>
<form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
</form>