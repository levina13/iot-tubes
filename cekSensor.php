<?php 
  //  $connect = mysqli_connect("localhost:3307", "root", "", "data_sensor");
//
  //  $sql = mysqli_query( $connect,"select * from kelembaban order by id desc");
    //$data = mysqli_fetch_array( $sql );
    //$value = $data["value_kelembaban"];

    //echo $value;
    $connect = mysqli_connect("localhost:3307", "root", "", "data_sensor");

    $sql = mysqli_query($connect, "SELECT * FROM kelembaban ORDER BY id DESC");
    $data = mysqli_fetch_array($sql);
    
    if ($data) {
        $value = $data["value"]; // Sesuaikan dengan nama kolom yang benar
        echo "LDR Value: " . $value;
    } else {
        echo "Data tidak ditemukan atau terjadi kesalahan.";
    }


?>