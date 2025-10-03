<?php
session_start();
include 'database.php';

// Check if admin is logged in
if (!isset($_SESSION["role"]) || $_SESSION["role"] != "admin") {
    header("Location: login.php");
    exit();
}

// Handle product addition
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["add_product"])) {
    $name = $_POST["name"];
    $price = $_POST["price"];
    $description = $_POST["description"];

    // Image upload
    $target_dir = "images/";
    $image = $target_dir . basename($_FILES["image"]["name"]);
    move_uploaded_file($_FILES["image"]["tmp_name"], $image);

    // Insert into database
    $sql = "INSERT INTO products(name, price, description, image) VALUES(?, ?, ?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sdss", $name, $price, $description, $image);
    $stmt->execute();
}

// Handle product deletion
if (isset($_GET["delete"])) {
    $id = intval($_GET["delete"]);
    if ($id > 0) {
        // Delete related orders
        $stmt = $conn->prepare("DELETE FROM orders WHERE product_id = ?");
        $stmt->bind_param("i", $id);
        $stmt->execute();

        // Delete product
        $stmt = $conn->prepare("DELETE FROM products WHERE id = ?");
        $stmt->bind_param("i", $id);
        $stmt->execute();
    }
    header("Location: admin.php");
    exit();
}

// Fetch products
$products = $conn->query("SELECT * FROM products");

// Fetch orders
$sql = "SELECT o.id AS order_id, o.customer_id, o.total_price, u.username, u.email
        FROM orders o
        JOIN users u ON o.customer_id = u.id
        ORDER BY o.order_date DESC";
$orders = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Admin Panel</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f6f8fa;
            margin: 0;
            padding: 20px;
        }
        .container {
            max-width: 900px;
            margin: auto;
            background: white;
            padding: 25px;
            border-radius: 10px;
            box-shadow: 0 0 12px rgba(0,0,0,0.1);
        }
        h2 {
            margin-top: 0;
            border-bottom: 2px solid #ddd;
            padding-bottom: 10px;
        }
        form input, form textarea, form button {
            width: 100%;
            margin: 10px 0;
            padding: 10px;
            border-radius: 6px;
            border: 1px solid #ccc;
        }
        form button {
            background-color: #28a745;
            color: white;
            border: none;
        }
        form button:hover {
            background-color: #218838;
        }
        table {
            width: 100%;
            margin-top: 25px;
            border-collapse: collapse;
        }
        table th, table td {
            border-bottom: 1px solid #ccc;
            padding: 10px;
            text-align: left;
        }
        table th {
            background-color: #f1f1f1;
        }
        img {
            width: 100px;
        }
        .delete-btn {
            background-color: #dc3545;
            color: white;
            padding: 6px 12px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            text-decoration: none;
        }
        .delete-btn:hover {
            background-color: #c82333;
        }
        .description-preview{
            max-height: 60px;
            overflow: hidden;
            cursor: pointer;
            position: relative;
        }
        .read-more{
            color: blue;
            cursor: pointer;
        }
    </style>
</head>
<body>

<div class="container">
    <h2>Admin Panel</h2>

    <!-- Add Product -->
    <h3>Add Product</h3>
    <form method="POST" enctype="multipart/form-data">
        <input type="text" name="name" required placeholder="Product Name">
        <input type="number" step="0.01" name="price" required placeholder="Price">
        <textarea name="description" required placeholder="Product Description"></textarea>
        <input type="file" name="image" required>
        <button type="submit" name="add_product">Add Product</button>
    </form>

    <!-- Products List -->
    <h3>Products List</h3>
    <table>
        <thead>
            <tr>
                <th>Image</th>
                <th>Name</th>
                <th>Price</th>
                <th>Description</th>
                <th>Delete</th>
            </tr>
        </thead>
        <tbody>
            <?php while ($row = $products->fetch_assoc()) : ?>
                <tr>
                    <td><img src="<?= $row['image'] ?>" alt="Image"></td>
                    <td><?= $row['name'] ?></td>
                    <td>₹<?= $row['price'] ?></td>
                    <td>
                        <div class="description-preview" onclick="expandDescription(this)">
                            <?= nl2br(htmlspecialchars($row['description'])) ?>
                        </div>
                        <small class="read-more" 
                        onclick="expandDescription(this.previousElementSibling)">Read More</small>
                    </td>
                    <td>
                        <a href="admin.php?delete=<?= $row['id'] ?>" onclick="return confirm('Delete this product?')" class="delete-btn">Delete</a>
                    </td>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>

    <!-- Customer Orders -->
    <h3>Customer Orders</h3>
    <table>
        <thead>
            <tr>
                <th>Order ID</th>
                <th>Customer</th>
                <th>Email</th>
                <th>Total Price</th>
            </tr>
        </thead>
        <tbody>
            <?php while ($order = $orders->fetch_assoc()) : ?>
                <tr>
                    <td><?= $order['order_id'] ?></td>
                    <td><?= $order['username'] ?></td>
                    <td><?= $order['email'] ?></td>
                    <td>₹<?= $order['total_price'] ?></td>
                </tr>
            <?php endwhile; ?>
        </tbody>
    </table>
</div>
<script>
    function expandDescription(el){
        el.style.maxHeight = 'none';
        if(el.nextElementSibling){
            el.nextElementSibling.style.display = 'none';
        }
    }
</script>
</body>
</html>