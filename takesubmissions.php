<?php
include "config.php";
include "check_token.php";  // Check user token

// Check user login or not
if(!isset($_SESSION['username'])){
 header('Location: index.php');
}

if($_POST["code"] == '')
{
	header("Location: submissions.php");
	
	//echo "<h1> EMPTY CODE </h1><br><h6>REDIRECTing...</h6>";
	
}

else 
{
	$re = mysqli_query($con, "SELECT active FROM contest");
	$r = mysqli_fetch_array($re);
	if ($r['active'] == '0')
		header("Location: submissions.php");
	else 
	{
		$code = mysqli_real_escape_string($con, $_POST["code"]);
		//$_POST["code"] = '';
		$lang = mysqli_real_escape_string($con, $_POST["language"]);
		//$_POST["language"] = '';
		$ques = mysqli_real_escape_string($con, $_POST["question"]);
		//$_POST["question"] = '';
		$teamid = $_SESSION['team_id'];
		
		$existing_AC = "SELECT COUNT(*) as cnt from submissions WHERE team_id = ".$teamid." and ques_id = ".$ques." and status = 1";
		$existing_AC_executed = mysqli_query($con, $existing_AC);
		$existing_AC_row = mysqli_fetch_array($existing_AC_executed);
		$count_existing_AC = $existing_AC_row['cnt'];
		if ($count_existing_AC != 0)
		{
			header("Location: ./respPages/alreadySubmitted.php");
		}
		else 
		{
		
			$q = "INSERT INTO submissions (team_id, ques_id, language, code, status) VALUES
				(".$teamid.",".$ques.",".$lang.",\"".$code."\",0)";
				
			if (mysqli_query($con, $q))
			{
				echo "recorded successfully<br>";
				$runid = mysqli_fetch_array(mysqli_query($con, "SELECT max(run_id) as runid FROM submissions WHERE team_id = ".$teamid))['runid'];
				$_SESSION['runid'] = $runid;
				if ($_POST["language"] == '1')
				{
					$myfile = fopen("backend/submissions/".$runid.".c", "w") or die("Unable to open file!");
					fwrite($myfile, $_POST["code"]);
					fclose($myfile);
				}
				if ($_POST["language"] == '2')
				{
					$myfile = fopen("backend/submissions/".$runid.".cpp", "w") or die("Unable to open file!");
					fwrite($myfile, $_POST["code"]);
					fclose($myfile);
				}
				if ($_POST["language"] == '3')
				{
					$myfile = fopen("backend/submissions/".$runid.".java", "w") or die("Unable to open file!");
					fwrite($myfile, $_POST["code"]);
					fclose($myfile);
				}
				if ($_POST["language"] == '4')
				{
					$myfile = fopen("backend/submissions/".$runid.".py", "w") or die("Unable to open file!");
					fwrite($myfile, $_POST["code"]);
					fclose($myfile);
				}
			
				$get_tl = mysqli_fetch_array(mysqli_query($con, "SELECT time_limit_c_cpp, time_limit_java, time_limit_python3 FROM questions WHERE ques_id = ".$_POST["question"]));
				$ccpptl = $get_tl["time_limit_c_cpp"];
				$javatl = $get_tl["time_limit_java"];
				$pythtl = $get_tl["time_limit_python3"];
				
				$command = "cd backend/bin/ && MainTest ".$runid." ".$ques." ";
				if ($_POST["language"] == '1')
				{
					$command = $command.$ccpptl." 1";
				}
				if ($_POST["language"] == '2')
				{
					$command = $command.$ccpptl." 2";
				}
				if ($_POST["language"] == '3')
				{
					$command = $command.$javatl." 3";
				}
				if ($_POST["language"] == '4')
				{
					$command = $command.$pythtl." 4";
				}
				
				$response = system($command, $reval);
				
				//echo $response."<br>";
				
				if ($response == '1'){
					echo "AC<br>";
					header("Location: ./respPages/AC.php");
				}
				if ($response == '2'){
					echo "WA<br>";
					header("Location: ./respPages/WA.php");
				}
				if ($response == '3'){
					echo "CE<br>";
					header("Location: ./respPages/CE.php");
				}
				if ($response == '4'){
					echo "RE<br>";
					header("Location: ./respPages/RTE.php");
				}
				if ($response == '5'){
					echo "TLE<br>";
					header("Location: ./respPages/TLE.php");
				}
			}
			
			else 
				echo "failed (contact administrator)";
			
		}
	}
}

?>