<html>
    <body>
        <form method="POST">
            value:<input type="number" id="val" name="val">
            <br>
            <input type="submit" name="submit" value="submit">
        </form>
    <body>
</html>
<?php
    if(isset($_POST["submit"])){
        $val=$_POST["val"];
        echo $val;
    }
?>
