<?php
// Konfigurasi koneksi database MySQL
$host = "localhost:3307"; // Alamat server database
$username = "root"; // Username database
$password = ""; // Password database
$database = "data_sensor"; // Nama database

// Membuat koneksi ke database
$connect = mysqli_connect($host, $username, $password, $database);

// Memeriksa koneksi database
if (!$connect) {
    die("Koneksi ke database gagal: " . mysqli_connect_error());
}

// Menerima data dari NodeMCU melalui metode POST
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $sensorValue = $_GET["sensor"];
    $minValue = 0; // Replace with the minimum value of the sensor range
    $maxValue = 1025; // Replace with the maximum value of the sensor range

// Convert sensor value to percentage
    $percentage = ( $maxValue-$sensorValue)/10 ;
    date_default_timezone_set('Asia/Jakarta');
    $currentDateTime = date("Y-m-d H:i:s");
    // Menyimpan data ke dalam tabel database
    $query = "INSERT INTO kelembaban (value, date) VALUES ('$percentage', '$currentDateTime')";
    
    // if (mysqli_query($connect, $query)) {
    //     echo "Data berhasil disimpan.";
    // } else {
    //     echo "Error: " . $query . "<br>" . mysqli_error($connect);
    // }
}

// Menutup koneksi database
//mysqli_close($connect);
?>
