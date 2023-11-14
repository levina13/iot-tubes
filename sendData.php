<?php
$connect = mysqli_connect("localhost", "root", "", "data_sensor");

$sensor = $_GET["sensor"];
date_default_timezone_set('Asia/Jakarta');
$currentDateTime = date("Y-m-d H:i:s");
$query = "INSERT INTO kelembaban (value, date) values ($sensor, '$currentDateTime')";
echo ($query);

// mysqli_query($connect, $query);
