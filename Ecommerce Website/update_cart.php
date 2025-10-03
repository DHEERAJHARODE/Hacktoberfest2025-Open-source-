<?php
session_start();
include 'database.php';

$user_id = $_SESSION['user_id']; // Make sure the user is logged in

// Update quantities
if (isset($_POST['quantities'])) {
    foreach ($_POST['quantities'] as $product_id => $quantity) {
        // Update quantity in cart table
        $stmt = $conn->prepare("UPDATE carts SET quantity = ? WHERE user_id = ? AND product_id = ?");
        $stmt->bind_param("iii", $quantity, $user_id, $product_id);
        $stmt->execute();
        $stmt->close();
    }
}

// Redirect back to cart page
header("Location: cart.php");
exit;