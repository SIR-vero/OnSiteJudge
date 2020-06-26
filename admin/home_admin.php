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
if (isset($_POST['yesdel']))
{
	mysqli_query($con, "DELETE FROM contest");
	mysqli_query($con, "DELETE FROM questions");
}

if (isset($_POST['stop']))
{
	mysqli_query($con,"update contest set active='0'");
}

if(isset($_POST['start']))
{
	$re = mysqli_fetch_array(mysqli_query($con, "SELECT * FROM contest"));
	if ($re['duration_in_sec'] == '0')
	{
		echo "<h2> Contest already FINISHED </h2> </br>";
	}
	else 
	{
		mysqli_query($con,"update contest set active='1'");
	}
}

if(isset($_POST['delete']))
{
	$re = mysqli_fetch_array(mysqli_query($con, "SELECT * FROM contest"));
	if ($re['active'] == '1')
	{
?>
			<h1> Deleting An Active Contest ! </br> Click YES to continue...</h1>
			<form method="post" action=''>
				<input type="submit" value="YES" name="yesdel"></br>
				<input type="submit" value="NO" name="nodel"></br>			
			</form>
<?php
		
	}
	else 
	{
?>
			<h1> Deleting the Contest ! </br> Click YES to continue...</h1>
			<form method="post" action=''>
				<input type="submit" value="YES" name="yesdel"></br>
				<input type="submit" value="NO" name="nodel"></br>			
			</form>
<?php
			
	}
}

if(isset($_POST['edit']))
{
	header("Location: editContest.php");
}

$re = mysqli_fetch_array(mysqli_query($con, "SELECT count(*) as cnt FROM contest"));
if ($re['cnt'] == '0')
{
	header("Location: configureContest.php");
}
else
{
	$re = mysqli_fetch_array(mysqli_query($con, "SELECT * FROM contest"));
	
	if ($re['active'] == '0')		//Contest not active
	{
		echo "<h1>".$re['contest_name']."  is not live </h1>";?>
		<form method='post' action=''>
			Start Contest:
			<input type="submit" value="Start" name="start"></br>
			Edit Contest:
			<input type="submit" value="Edit" name="edit"> </br>
			Delete Contest:
			<input type="submit" value="Delete" name="delete">
		</form>
<?php	
	}
	else 
	{
		echo "<h1>".$re['contest_name']." is live </h1>";
?>
		<form method='post' action=''>
			Stop Contest:
			<input type="submit" value="Stop" name="stop"></br>
			Edit Contest:
			<input type="submit" value="Edit" name="edit"> </br>
			Delete Contest:
			<input type="submit" value="Delete" name="delete">
		</form>
<?php
	}
}

?>

<form method='post' action="">
   <input type="submit" value="Logout" name="but_logout">
  </form>