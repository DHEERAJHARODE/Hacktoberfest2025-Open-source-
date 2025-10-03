<?php
session_start();
include 'database.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['product_id'])) {
    $product_id = intval($_POST['product_id']);
    $user_id = $_SESSION['user_id']; 
    
    // Get product from DB
    $stmt = $conn->prepare("SELECT * FROM products WHERE id = ?");
    $stmt->bind_param("i", $product_id);
    $stmt->execute();
    $product = $stmt->get_result()->fetch_assoc();
    $stmt->close();

    if ($product) {
        // Check if this product is already in the user's cart
        $stmt = $conn->prepare("SELECT quantity FROM carts WHERE user_id = ? AND product_id = ?");
        $stmt->bind_param("ii", $user_id, $product_id);
        $stmt->execute();
        $result = $stmt->get_result();
        $stmt->close();

        if ($result->num_rows > 0) {
            // Product already in cart, update quantity
            $stmt = $conn->prepare("UPDATE carts SET quantity = quantity + 1 WHERE user_id = ? AND product_id = ?");
            $stmt->bind_param("ii", $user_id, $product_id);
            $stmt->execute();
            $stmt->close();
        } else {
            // Product not in cart, add new
            $quantity = 1;  // Assign quantity value before bind_param
            $stmt = $conn->prepare("INSERT INTO carts (user_id, product_id, quantity) VALUES (?, ?, ?)");
            $stmt->bind_param("iii", $user_id, $product_id, $quantity);  // Pass the variable reference
            $stmt->execute();
            $stmt->close();
        }

        // Redirect with success message
        header("Location: ".$_SERVER['HTTP_REFERER']."?message=" . urlencode($product['name'] . " added to cart!"));
        exit;
    } else {
        header("Location: index.php?message=" . urlencode("Product not found!"));
        exit;
    }
}
?>