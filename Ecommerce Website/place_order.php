<?php
session_start();
include 'database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit;
}

$user_id = $_SESSION['user_id'];
$address = $_POST['address'];
$payment_method = $_POST['payment_method'];
$total_price = $_POST['total_price'];
$payment_status = ($payment_method === 'cod') ? 'Pending' : 'Paid';
$order_date = date("Y-m-d H:i:s");

$order_summary = [];

// Fetch cart data from database
$sql = "SELECT p.id AS product_id, p.name, p.price, c.quantity 
        FROM carts c
        JOIN products p ON c.product_id = p.id
        WHERE c.user_id = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result();

while ($row = $result->fetch_assoc()) {
    $product_id = $row['product_id'];
    $product_name = $row['name'];
    $price = $row['price'];
    $quantity = $row['quantity'];
    $product_total = $price * $quantity;

    // Insert order into orders table
    $stmt_insert = $conn->prepare("INSERT INTO orders (customer_id, product_id, quantity, total_price, payment_method, payment_status, order_date)
                                   VALUES (?, ?, ?, ?, ?, ?, ?)");
    $stmt_insert->bind_param("iiidsss", $user_id, $product_id, $quantity, $product_total, $payment_method, $payment_status, $order_date);
    $stmt_insert->execute();
    $stmt_insert->close();

    $order_summary[] = [
        'name' => $product_name,
        'price' => $price,
        'quantity' => $quantity,
        'subtotal' => $product_total
    ];
}
$stmt->close();

// Set session values for thank you page
$_SESSION['order_summary'] = $order_summary;
$_SESSION['total_price'] = $total_price;
$_SESSION['payment_method'] = $payment_method;

// Clear cart from database
$delete = $conn->prepare("DELETE FROM carts WHERE user_id = ?");
$delete->bind_param("i", $user_id);
$delete->execute();
$delete->close();

// Redirect to thank you page
header("Location: thank_you.php");
exit;
?>