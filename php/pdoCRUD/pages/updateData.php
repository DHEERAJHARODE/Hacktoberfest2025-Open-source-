<?php

require "../includes/config.php";
$id = $_REQUEST['update'];
$obj = new db;
$user = $obj->viewSingleData($id);

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD PROJECT</title>
    <link rel="stylesheet" href="../assets/style.css">
</head>

<body>
    <label for="heading">Crud Using PDO</label>
    <hr>
    <div class="container">
        <form method="POST">
            <label for="sub-heading">Update Record</label>
            <input type="text" name="name" value="<?php echo $user['name']; ?>" required>
            <br>
            <input type="text" name="email" value="<?php echo $user['email']; ?>" required>
            <br>
            <input type="text" name="mobile" value="<?php echo $user['mobile']; ?>" required>
            <br>
            <input class="btnSubmit" type="submit" value="Update" name="btnSubmit">
        </form>
    </div>
    <br>
    <br>
    <a href="./viewData.php" class="goBack">View Data</a>
</body>

</html>

<?php

if (isset($_POST['btnSubmit'])) {
    if ($_REQUEST['update']) {
        $id = $_GET['update'];
        $name = $_POST['name'];
        $email = $_POST['email'];
        $mobile = $_POST['mobile'];
        $obj->updateData($id, $name, $email, $mobile);
        header('Location: viewData.php');
    }
}

?>