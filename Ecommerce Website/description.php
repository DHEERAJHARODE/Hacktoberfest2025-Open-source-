<?php
include 'database.php';

if (!isset($_GET['id'])) {
    echo "No product ID provided.";
    exit;
}

$id = intval($_GET['id']);
$sql = "SELECT * FROM products WHERE id = $id";
$result = $conn->query($sql);

if ($result->num_rows == 0) {
    echo "Product not found.";
    exit;
}

$product = $result->fetch_assoc();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title><?php echo $product['name']; ?> - Description</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
<?php include 'header.php'; ?>

<div class="container" style="margin-top: 30px;">
    <div class="product-desc">
        <img src="<?php echo $product['image']; ?>" alt="<?php echo $product['name']; ?>">
        <h2><?php echo $product['name']; ?></h2>
        <p><strong>Price: </strong><?php echo $product['price']; ?> Rs</p>
        <p style="margin-top: 15px;"><?php echo nl2br($product['description']); ?></p>

        <form action="add_to_cart.php" method="POST" style="margin-top: 20px;">
            <input type="hidden" name="product_id" value="<?php echo $product['id']; ?>">
            <button type="submit">Add to Cart</button>
        </form>

        <br>
        <a href="<?php echo
        htmlspecialchars($_SERVER['HTTP_REFERER']?? 'index.php'); ?>S"><button>Back</button></a>
    </div>
</div>

<?php include 'footer.php'; ?>
</body>
</html>