<?php
	require 'database.php';
	$res=null;
	if(isset($_POST["submit"])) {
	$uname = $_POST["uname"];
	$fname = $_POST["fname"];
	$lname = $_POST["lname"];
	$email = $_POST["email"];
	$pwd = $_POST["pwd"];
	$cpwd = $_POST["cpwd"];
	$gender = $_POST["gender"];
	
	if(empty($uname)||empty($fname)||empty($lname)||empty($pwd)||empty($cpwd)||empty($gender)) {
		$res="Please fill all the Fields !!!";
	}
	else if(!filter_var($email,FILTER_VALIDATE_EMAIL)) {
		$res="Wrong email Address !!!";
	}
	else if($pwd !== $cpwd) {
		$res="Password did not match !!!";
	}
	else {
		$sql = "Select username from users where username = '$uname' ";
		$result = mysqli_query($conn, $sql);
		if(mysqli_num_rows($result)>0) {
			$res="Username already exist !!!";
		}
		else {
			$sql = "Insert into users(username,lname,fname,email,passwd,gender) values('$uname','$fname','$lname','$email','$pwd','$gender') ";
			mysqli_query($conn,$sql);
			$res="Successfully Registered !!!";
		}	
	}
	}
	
?>

<html>
 <head>
  <link rel="stylesheet" type="text/css" href="sn.css" />
  </head>
   <title>Registration Form Design</title>
	<body>
		<div class="loginbox">
		<img src="abc.png" class="abc">
			<h1>Register Here</h1>
			<form action="reg.php" method="post" >
				
				<div class="inputBox">
				
				<input type="text" name="uname" required="">
				<label>Enter Username</label>
				</div>
				<div class="inputBox">
				<input type="text" name="fname" required="" >
				<label>Enter First Name</label>
				</div>
				<div class="inputBox">
				<input type="text" name="lname" required="">
				<label>Enter Last Name</label>
				</div>
				<div class="inputBox">
				<input type="text" name="email" required="">
				<label>Enter Email</label>
				</div>
				<div class="inputBox">
				<input type="text" name="pwd" required="">
				<label>Enter Password</label>
				</div>
				<div class="inputBox">
				<input type="password" name="cpwd" required="">
				<label>Re-enter Password</label>
				</div>
				Gender: <select name="gender" class="gender"> 
				<option value="M"> Male </option>
				<option value="F"> Female </option>
				</select>
				<input type="submit" name="submit" value="Sign Up"><br>
				<div><?php echo $res; ?> </div>
				<a href="#">Already Registered?</a><br>
			</form>
		</div>
		
	</body>
</html>