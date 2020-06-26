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
$re = mysqli_fetch_array(mysqli_query($con,"SELECT * FROM contest"));
$errorArray = array();
$errorArray = array_fill(0, $re['questions'], "");
$errorArrayinfile = array();
$errorArrayinfile = array_fill(0, $re['questions'], "");
$errorArrayoutfile = array();
$errorArrayoutfile = array_fill(0, $re['questions'], "");
$error = "";
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
	for ($x = 1; $x <= $re['questions']; $x++)
	{
		if (empty($_POST[$x.'ques_name']))
		{
			$error = "error";
			$errorArray[$x - 1] = "Question name REQUIRED";
		}
		if($_FILES[$x.'input_file']['name'] == "")
		{
			$error = "error";
			$errorArrayinfile[$x - 1] = "Input file REQUIRED";
		}
		if($_FILES[$x.'output_file']['name'] == "")
		{
			$error = "error";
			$errorArrayoutfile[$x - 1] = "Output file REQUIRED";
		}
	}
	if (empty($error))
	{
		for ($x = 1; $x <= $re['questions']; $x++)
		{
			$quesname = mysqli_real_escape_string($con, $_POST[$x.'ques_name']);
			$shortname = mysqli_real_escape_string($con, $_POST[$x.'short_ques_name']);
			mysqli_query($con, "INSERT INTO questions(ques_id, ques_name, short_name, time_limit_c_cpp, time_limit_java, time_limit_python3, points) values(".$x.", '".$quesname."', '".$shortname."', ".$_POST[$x.'tlccpp'].", ".$_POST[$x.'tljava'].", ".$_POST[$x.'tlpyth'].", ".$_POST[$x.'point'].")");                                  
			$in_file = "../backend/testCases/".$x.".txt";
			$out_file = "../backend/answerFiles/".$x.".txt";
			if (move_uploaded_file($_FILES[$x.'input_file']['tmp_name'], $in_file))
				echo "input file recorded successfully";
			else 
				echo "failed to record in file";
			if (move_uploaded_file($_FILES[$x.'output_file']['tmp_name'], $out_file))
				echo "output file recorded successfully";
			else 
				echo "failed to record out file";
		}
	}
}
?>


<?php

if (!isset($_POST['second']) or !empty($error))
{
for ($x = 1; $x <= $re['questions']; $x++)
{
	echo "enter the details of :".$x." question:</br>";
?>
	<form action="" method="post" enctype="multipart/form-data">
		Enter Question Name: 
		<input type="text" name="<?php echo $x;?>ques_name">
		<?php echo $errorArray[$x - 1]; ?>
		</br>
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
		<input type="file" name="<?php echo $x;?>input_file">
		<?php echo $errorArrayinfile[$x - 1]; ?>
		</br>
		Select output file :
		<input type="file" name="<?php echo $x;?>output_file">
		<?php echo $errorArrayoutfile[$x - 1]; ?>
		</br>
		
		
		</br></br>

<?php
}
?>
		<input type="submit" value="Done" name="second">
	</form>
<?php
}
?>
<form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
</form>