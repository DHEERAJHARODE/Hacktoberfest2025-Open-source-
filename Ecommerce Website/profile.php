<?php
session_start();
include 'database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit;
}

$user_id = $_SESSION['user_id'];

// Fetch orders for the user
$sql = "SELECT o.*, p.name AS product_name, p.description, p.price, p.image
        FROM orders o
        JOIN products p ON o.product_id = p.id
        WHERE o.customer_id = ?
        ORDER BY o.order_date DESC";

$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result();
$orders = $result->fetch_all(MYSQLI_ASSOC);
$stmt->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My Orders - Manhwa Store</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        .container {
            max-width: 900px;
            margin: 40px auto;
            padding: 20px;
        }

        .orders-section h3 {
            margin-bottom: 20px;
        }

        .order-card {
            display: flex;
            border: 1px solid #ddd;
            border-radius: 8px;
            padding: 15px;
            margin-bottom: 20px;
            background-color: #fff;
            box-shadow: 0 1px 4px rgba(0,0,0,0.05);
        }

        .order-card img {
            width: 100px;
            height: 120px;
            object-fit: cover;
            border-radius: 4px;
            margin-right: 20px;
        }

        .order-details {
            flex-grow: 1;
        }

        .order-details h4 {
            margin: 0 0 5px;
        }

        .order-details p {
            margin: 3px 0;
            font-size: 14px;
            color: #333;
        }
    </style>
</head>
<body>

<?php include 'header.php'; ?>

<div class="container">
    <div class="orders-section">
        <h3>My Orders</h3>
        <?php if (count($orders) > 0): ?>
            <?php foreach ($orders as $order): ?>
                <div class="order-card">
                    <img src="<?= htmlspecialchars($order['image']) ?>" alt="<?= htmlspecialchars($order['product_name']) ?>">
                    <div class="order-details">
                        <h4><?= htmlspecialchars($order['product_name']) ?></h4>
                        <p><?= htmlspecialchars($order['description']) ?></p>
                        <p><strong>Quantity:</strong> <?= $order['quantity'] ?></p>
                        <p><strong>Price:</strong> ₹<?= $order['price'] ?></p>
                        <p><strong>Estimated Delivery:</strong> 
                            <?php
                                $deliveryDate = date('F j, Y', strtotime($order['order_date'] . ' +7 days'));
                                echo $deliveryDate;
                            ?>
                        </p>
                    </div>
                </div>
            <?php endforeach; ?>
        <?php else: ?>
            <p>You have not placed any orders yet.</p>
        <?php endif; ?>
    </div>
</div>

<?php include 'footer.php'; ?>

</body>
</html>