<?php
session_start();
include 'database.php';
$sql = "SELECT * FROM products LIMIT 6";
$result = $conn->query($sql);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Manhwa Store - Home</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
<?php include 'header.php'; ?>

<h2 style="text-align:center; margin-top:20px;">Featured Manhwas</h2>

<div class="container">
    <?php while($row = $result->fetch_assoc()): ?>
        <div class="product">
            <div>
                <img src="<?php echo $row['image']; ?>" alt="<?php echo $row['name']; ?>">
                <h3><?php echo $row['name']; ?></h3>
                <p><?php echo substr($row['description'], 0, 60); ?>...</p>
                <p><strong><?php echo $row['price']; ?> Rs</strong></p>
            </div>

            <!-- View Description Button -->
            <form action="description.php" method="GET" style="margin-bottom: 10px;">
                <input type="hidden" name="id" value="<?php echo $row['id']; ?>">
                <button type="submit">View Description</button>
            </form>

            <!-- Add to Cart Button -->
            <form action="add_to_cart.php" method="POST">
                <input type="hidden" name="product_id" value="<?php echo $row['id']; ?>">
                <button type="submit">Add to Cart</button>
            </form>
        </div>
    <?php endwhile; ?>
</div>

<?php include 'footer.php'; ?>
</body>
</html>