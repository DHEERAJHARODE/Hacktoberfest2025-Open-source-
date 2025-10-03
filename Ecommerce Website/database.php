<?php
// Database connection
$servername = "localhost";
$username = "root"; 
$password = ""; 
$dbname = "manhwa";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Define default admin credentials
$admin_email = "raodipayan@gmail.com";
$admin_password = "admin123";
$hashed_password = password_hash($admin_password, PASSWORD_DEFAULT);

// Check if admin already exists
$sql = "SELECT * FROM users WHERE email = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $admin_email);
$stmt->execute();
$result = $stmt->get_result();

if ($result->num_rows === 0) {
    // Insert default admin if not found
    $sql = "INSERT INTO users (email, password, role) VALUES (?, ?, 'admin')";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ss", $admin_email, $hashed_password);
    $stmt->execute();
}

// Close the statement
$stmt->close();
?>