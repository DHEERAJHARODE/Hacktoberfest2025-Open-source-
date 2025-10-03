<?php
session_start();
if (!isset($_SESSION['order_summary']) || !isset($_SESSION['total_price']) || !isset($_SESSION['payment_method'])) {
    header("Location: products.php");
    exit;
}

$deliveryDate = date('F j, Y', strtotime('+7 days'));
?>
<!DOCTYPE html>
<html>
<head>
    <title>Thank You</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        .thankyou-container {
            max-width: 800px;
            margin: 80px auto;
            padding: 20px;
            text-align: center;
            background-color: #f9f9f9;
            border-radius: 8px;
        }
        table {
            width: 100%;
            margin-top: 20px;
            border-collapse: collapse;
            background-color: #fff;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 12px;
        }
        th {
            background-color: #f0f0f0;
        }
        .summary {
            margin-top: 30px;
            font-size: 16px;
        }
        .btn {
            margin-top: 30px;
            padding: 12px 24px;
            background-color: #4CAF50;
            color: white;
            border: none;
            font-size: 16px;
            cursor: pointer;
            text-decoration: none;
            display: inline-block;
            border-radius: 4px;
        }
        .btn:hover {
            background-color: #45a049;
        }
    </style>
</head>
<body>

<?php include 'header.php'; ?>

<div class="thankyou-container">
    <h2>Thank You for Your Order!</h2>
    <p>Your order has been placed successfully and will be delivered by <strong><?php echo $deliveryDate; ?></strong>.</p>

    <h3 style="margin-top: 30px;">Order Summary</h3>
    <table>
        <thead>
            <tr>
                <th>Product</th>
                <th>Quantity</th>
                <th>Price (Each)</th>
                <th>Subtotal</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($_SESSION['order_summary'] as $item): ?>
                <tr>
                    <td><?php echo htmlspecialchars($item['name']); ?></td>
                    <td><?php echo $item['quantity']; ?></td>
                    <td>₹<?php echo $item['price']; ?></td>
                    <td>₹<?php echo $item['quantity'] * $item['price']; ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>

    <div class="summary">
        <p><strong>Total Price:</strong> ₹<?php echo $_SESSION['total_price']; ?></p>
        <p><strong>Payment Method:</strong> <?php echo strtoupper($_SESSION['payment_method']); ?></p>
    </div>

    <a class="btn" href="products.php">Continue Shopping</a>
</div>

<?php include 'footer.php'; ?>

</body>
</html>