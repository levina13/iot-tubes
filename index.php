<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://cdn.tailwindcss.com"></script>
    <script type="text/javascript" src="jquery/jquery.min.js"></script>
    <title>Document</title>
    <script type="text/javascript">
        $(document).ready(function(){
            setInterval(function(){
                $("#cekSensor").load('cekSensor.php');
            }, 500);
        });
    </script>
</head>
<body>
    <div>
        LDR Value : <span id="cekSensor"></span>
    </div>
</body>

</html>