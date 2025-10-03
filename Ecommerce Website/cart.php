<?php
session_start();
include 'database.php';

$user_id = $_SESSION['user_id']; 

// Get all items in the cart for the user
$stmt = $conn->prepare("SELECT p.name, p.price, p.image, c.quantity, p.id AS product_id 
                       FROM carts c
                       JOIN products p ON c.product_id = p.id
                       WHERE c.user_id = ?");
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result();

$grand_total = 0;
?>

<!DOCTYPE html>
<html>
<head>
    <title>Your Cart</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        .cart-table-container {
            max-height: 400px;
            overflow-y: auto;
            margin: 20px auto;
            width: 90%;
            border: 1px solid black;
            border-radius: 4px;
        }

        .cart-table {
            width: 100%;
            border-collapse: collapse;
        }

        .cart-table th, .cart-table td {
            border: 1px solid black;
            padding: 12px;
            text-align: center;
        }

        .cart-table img {
            width: 60px;
            height: auto;
        }

        .cart-total {
            text-align: right;
            padding: 20px;
            width: 90%;
            margin: auto;
            font-size: 18px;
        }

        .cart-actions {
            display: flex;
            justify-content: space-between;
            align-items: center;
            width: 90%;
            margin: 30px auto;
        }

        .cart-actions a, .cart-actions button {
            background-color: #28a745;
            padding: 12px 20px;
            color: white;
            text-decoration: none;
            border: none;
            border-radius: 4px;
            font-size: 16px;
        }

        .cart-actions button:hover, .cart-actions a:hover {
            background-color: #218838;
        }

        .remove-btn {
            background-color: red;
            padding: 8px 12px;
            border: none;
            color: white;
            border-radius: 4px;
        }

        .remove-btn:hover {
            background-color: #c82333;
        }

        input[type="number"] {
            width: 60px;
            padding: 4px;
        }

        body {
            margin: 0;
            padding-bottom: 100px; 
        }
    </style>
</head>
<body>

<?php include 'header.php'; ?>

<h2 style="text-align:center; margin-top:20px;">Your Shopping Cart</h2>

<?php if ($result->num_rows > 0): ?>
    <form method="post" action="update_cart.php">
        <div class="cart-table-container">
            <table class="cart-table">
                <tr>
                    <th>Image</th>
                    <th>Name</th>
                    <th>Qty</th>
                    <th>Price (Rs)</th>
                    <th>Total (Rs)</th>
                    <th>Action</th>
                </tr>
                <?php 
                while ($row = $result->fetch_assoc()): 
                    $item_total = $row['price'] * $row['quantity'];
                    $grand_total += $item_total;
                ?>
                <tr>
                    <td><img src="<?php echo htmlspecialchars($row['image']); ?>" alt="<?php echo htmlspecialchars($row['name']); ?>"></td>
                    <td><?php echo htmlspecialchars($row['name']); ?></td>
                    <td>
                        <input type="number" name="quantities[<?php echo $row['product_id']; ?>]" value="<?php echo $row['quantity']; ?>" min="1">
                    </td>
                    <td><?php echo $row['price']; ?></td>
                    <td><?php echo $item_total; ?></td>
                    <td>
                        <a href="remove_from_cart.php?product_id=<?php echo $row['product_id']; ?>" class="remove-btn">Remove</a>
                    </td>
                </tr>
                <?php endwhile; ?>
            </table>
        </div>

        <div class="cart-total">
            <strong>Grand Total: ₹<?php echo $grand_total; ?></strong>
        </div>

        <div class="cart-actions">
            <button type="submit">Update Cart</button>
            <a href="checkout.php">Proceed to Checkout</a>
        </div>
    </form>
<?php else: ?>
    <p style="text-align:center;">Your cart is still empty.</p>
<?php endif; ?>

<?php include 'footer.php'; ?>

</body>
</html>