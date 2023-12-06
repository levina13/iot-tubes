<!DOCTYPE html>
<html>
<head>
    <title>Monitor Sensor</title>
</head>
<body>
    <h1>Data Sensor</h1>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Value</th>
            <th>Date</th>
        </tr>
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

        // Mengambil data dari tabel kelembaban
        $query = "SELECT * FROM kelembaban ORDER BY id DESC";
        $result = mysqli_query($connect, $query);

        if (mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . $row["id"] . "</td>";
                echo "<td>" . $row["value"] . "</td>";
                echo "<td>" . $row["date"] . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='3'>Tidak ada data sensor.</td></tr>";
        }

        // Menutup koneksi database
        mysqli_close($connect);
        ?>
    </table>
</body>
</html>
