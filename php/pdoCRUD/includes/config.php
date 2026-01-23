<?php 

    class db{
        public $con;

        function __construct(){
            $dsn = 'mysql:host=localhost;dbname=test';
            $uname = 'root';
            $pwd = '';

            $this->con = new PDO($dsn, $uname, $pwd);
        }

        function insertData($name, $email, $mobile){
            $query = "INSERT INTO data(name, email, mobile) VALUES(:name, :email, :mobile)";
            $stmt = $this->con->prepare($query);
            $stmt->bindParam(':name', $name);
            $stmt->bindParam(':email', $email);
            $stmt->bindParam(':mobile', $mobile);
            $stmt->execute();
        }

        function viewData(){
            $query = "SELECT * FROM data";
            $stmt = $this->con->prepare($query);
            $stmt->execute();
            return $stmt->fetchAll(PDO::FETCH_ASSOC);
        }

        function deleteData($id){
            $query = "DELETE FROM data WHERE id = :id";
            $stmt = $this->con->prepare($query);
            $stmt->bindParam(':id',$id);
            $stmt->execute();
        }

        function viewSingleData($id){
            $query = "SELECT * FROM data WHERE id = :id";
            $stmt = $this->con->prepare($query);
            $stmt->bindParam(':id',$id);
            $stmt->execute();
            return $stmt->fetch();
        }

        function updateData($id, $name, $email, $mobile){
            $query = "UPDATE data SET name = :name, email = :email, mobile = :mobile WHERE id = :id";
            $stmt = $this->con->prepare($query);
            $stmt->bindParam(':id', $id);
            $stmt->bindParam(':name', $name);
            $stmt->bindParam(':email', $email);
            $stmt->bindParam(':mobile', $mobile);
            $stmt->execute();
        }        
    }