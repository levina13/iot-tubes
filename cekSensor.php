<?php 
    $connect = mysqli_connect("localhost", "root", "", "data_sensor");

    $sql = mysqli_query( $connect,"select * from kelembapan order by id desc");
    $data = mysqli_fetch_array( $sql );
    $value = $data["value_kelembapan"];

    echo $value;
?>