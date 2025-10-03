<?php
session_start();
include 'database.php';

if (isset($_GET['product_id'])) {
    $product_id = intval($_GET['product_id']);
    $user_id = $_SESSION['user_id']; 

    // Delete the item from the cart
    $stmt = $conn->prepare("DELETE FROM carts WHERE user_id = ? AND product_id = ?");
    $stmt->bind_param("ii", $user_id, $product_id);
    $stmt->execute();
    $stmt->close();
}

header("Location: cart.php");
exit;