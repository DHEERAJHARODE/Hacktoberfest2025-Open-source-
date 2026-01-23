<?php

require "../includes/config.php";
$obj = new db();
$user = $obj->viewData();

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD PROJECT</title>
    <style>
        * {
            font-family: cursive;
            font-weight: 500;
            font-size: large;
        }

        hr {
            width: 50%;
            border: 1px solid lightgray;
            margin-bottom: 20px;
        }

        label {
            font-weight: bolder;
            font-size: x-large;
            justify-content: center;
            align-items: center;
            display: flex;
            padding-top: 20px;
        }

        .container {
            border: 1px solid lightgray;
            width: 700px;
            padding: 20px;
            text-align: center;
            margin: auto;
            border-radius: 10px;
        }

        table {
            border-collapse: collapse;
            border: 1px solid blue;
            display: flex;
            padding: 20px;
            align-items: center;
            justify-content: center;
            border-radius: 4px;
            text-align: center;
        }

        a {
            text-decoration: none;
            color: blue;
        }

        .goBack {
            padding: 10px 20px;
            border-radius: 5px;
            background-color: white;
            color: black;
            cursor: pointer;
            text-decoration: none;
        }

        .goBack:hover {
            border: 1px solid black;
            border-radius: 6px;
        }

    </style>
</head>

<body>
    <label for="heading">Crud Using PDO</label>
    <hr>
    <div class="container">
        <form method="post">
            <table border="1">
                <tr>
                    <td>ID</td>
                    <td>Name</td>
                    <td>Email</td>
                    <td>Mobile Number</td>
                    <td>Action</td>
                </tr>
                <?php foreach ($user as $data) {
                ?>
                    <tr>
                        <td><?php echo $data['id']; ?></td>
                        <td><?php echo $data['name']; ?></td>
                        <td><?php echo $data['email']; ?></td>
                        <td><?php echo $data['mobile']; ?></td>
                        <td>
                            <a href="viewData.php?delete=<?php echo $data['id']; ?>">Delete</a>&nbsp;|
                            <a href="updateData.php?update=<?php echo $data['id']; ?>">Update</a>
                        </td>
                    </tr>
                <?php
                }
                ?>
            </table>
            <br>
            <a href="../index.php" class="goBack">Go Back</a>
        </form>
    </div>
</body>

</html>

<?php

if (isset($_REQUEST['delete'])) {
    $id = $_REQUEST['delete'];
    $obj->deleteData($id);
    header('Location: viewData.php');
}

?>