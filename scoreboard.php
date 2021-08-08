<?php
include "config.php";
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
		$contest = mysqli_query($con, "SELECT * FROM contest");
		$contestRow = mysqli_fetch_array($contest);
		echo "<h2>".$contestRow['contest_name']." is ";
		if($contestRow['active'] == 1)
		{
			echo "live </h2></br>";
		}
		else 
		{
			echo "not Live</h2></br>";
		}
		$scoreQueryResult = mysqli_query($con, "SELECT team_id, count(*) as solved FROM submissions WHERE status = 1 GROUP BY team_id ORDER by solved DESC");
		
		echo "<table>";
		echo "<tr>
				<th>Team ID</th>
				<th>Solved</th>
			  </tr>";
		
		while($scoreQueryResultArray = mysqli_fetch_array($scoreQueryResult))
		{
			echo "<tr>";
			echo "<td>".$scoreQueryResultArray['team_id']."</td>";
			echo "<td>".$scoreQueryResultArray['solved']."</td>";
			echo "</tr>";
		}
		echo "</table>";
	}
  ?>