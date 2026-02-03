### Shubh Sarthak Sahu
-Photo: https://imgur.com/z6b0cMl
-Location:India
-Github: https://github.com/thelifeofshubh
 
 This is a 3D text shadow
 
HTML:
<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet"href="app.css">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1 data-text="shadow">Shadow</h1>
</body>
</html>

CSS:
body {
    background: #aaa;
    display: flex;
    align-items: center;
    justify-content: center;
    height: 100vh;
  }
  h1 {
   font-family: 'Montserrat', sans-serif;
    text-transform: uppercase;
    color: white;
    font-size: 15vw;
  background: linear-gradient(-90deg, rgb(223 223 223) 0%, rgba(190,190,190,1) 100%);

    line-height: 1;
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    position: relative;

  }
  h1:before {
  content: attr(data-text);
      -webkit-background-clip: none;
      -webkit-text-fill-color: black;
      position: absolute;
      z-index: -1;
      filter: blur(14px);
      transform: skew(67deg, 0) translate(-20%, 15%) scaleY(0.5);
      -webkit-mask-image: linear-gradient(180deg, rgba(255,255,255,0) 0%, rgba(0,0,0,1) 100%);
      padding: 0 22px;
  }
