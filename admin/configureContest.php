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

$error = $nameerror = $durationerror = $queserror = "";
$dur = $quest = "";
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	$quest = $_POST['tenth_question']*10 + $_POST['oneth_question'];
	$dur =  ($_POST['hundereth_min']*100 + $_POST['tenth_min']*10 + $_POST['oneth_min'])*60 + $_POST['tenth_sec']*10 + $_POST['oneth_sec'];
	if (empty($_POST['contest_name']))
	{
		$error = "error";
		$nameerror = "Contest name id REQUIRED";
	}
	
	if ($dur == 0)
	{
		$error = "error";
		$durationerror = "set duration more than 0 second";	
	}
	if ($quest == 0)
	{
		$error = "error";
		$queserror = "set atleast one ques";	
	}
}


if (!isset($_POST['first']) or !empty($error))
{
?>

<h1>Configure Contest</h1>
*REQUIRED
	<form method="post" action=''>
		1) Enter Contest Name : *
		<input type="text" name="contest_name" placeholder="Enter the Contest name here">
		<?php echo $nameerror; ?>
		</br>
		2) Enter Duration of Contest : *
		<select id="hundereth_min" name="hundereth_min">
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
		</select>
		<select id="tenth_min" name="tenth_min">
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
		</select>
		<select id="oneth_min" name="oneth_min">
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
		</select>
		minute(s)
		<select id="tenth_sec" name="tenth_sec">
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
		</select>
		<select id="oneth_sec" name="oneth_sec">
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
		</select>
		second(s)
		<?php echo $durationerror; ?>
		</br>
		3) Enter Number Of Questions : *
		<select id="tenth_question" name="tenth_question">
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
		</select>
		<select id="oneth_question" name="oneth_question">
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
		</select>
		<?php echo $queserror; ?>
		</br>
		<input type="submit" name="first" value="Done">
	</form>
<?php
}
else 
{
	$cntstname = mysqli_real_escape_string($con, $_POST['contest_name']);
	mysqli_query($con, "INSERT INTO contest(id, contest_name, duration_in_sec, questions, active) values(1, '".$cntstname."', '".$dur."', '".$quest."', 0)");
	header("Location: questionDetails.php");
}
?>



<form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
</form>