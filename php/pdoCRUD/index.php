<?php 

    require "./includes/config.php";
    $obj = new db();

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD PROJECT</title>
    <link rel="stylesheet" href="./assets/style.css">
</head>

<body>
    <label for="heading">Crud Using PDO</label>
    <hr>
    <div class="container">
        <form method="POST">
            <label for="sub-heading">Add New Record</label>
            <input type="text" name="name" placeholder="Enter Name" required>
            <br>
            <input type="email" name="email" placeholder="Enter Email" required>
            <br>
            <input type="text" name="mobile" placeholder="Enter Mobile Number" required>
            <br>
            <input class="btnSubmit" type="submit" value="Add" name="btnSubmit">
        </form>
    </div>
        <br>
        <br>
        <a href="./pages/viewData.php" class="goBack">View Data</a>
</body>
</html>

<?php 

    if(isset($_POST['btnSubmit'])){
        $name = $_POST['name'];
        $email = $_POST['email'];
        $mobile = $_POST['mobile'];

        $obj->insertData($name, $email, $mobile);
        header('Location: ./pages/viewData.php');
    }

?>