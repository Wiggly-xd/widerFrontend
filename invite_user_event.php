<?php
//Headers
header('Access-Control-Allow-Origin: *');
header('Content-Type: application/json');
header('Access-Control-Allow-Methods: PUT');
header('Access-Control-Allow-Headers: Access-Control-Allow-Headers,Content-Type,Access-Control-Allow-Methods,Authorization,X-Requested-With');

include_once '../../config/Database.php';
include_once '../authentication/auth2.php';
//here we authenticate and make sure that the key that the user sends is correct. if so the rest of the code is excecuted.

$API = "";
if(isset($_REQUEST['API']))
    $API = $_REQUEST['API'];
    
if(verify($API)){
include_once '../../models/event.php';

//Instantiate DB & connect
$database = new Database();
$db = $database->connect();

//Instantiate event object
$event = new Event($db);

//Get raw posted data
$data = json_decode(file_get_contents("php://input"));

//Set eventID to UPDATE
$event->inviteID = $data->inviteID;
$event->eventID = $data->eventID;

//Update event and encode and print out our JSON.

if($event->invite_user_event()){
    echo json_encode(
        array('message' => 'user Invited')
    );
}else{
    echo json_encode(
        array('message' => 'user Not Invited')
    );
}
}else{
    echo false;
}
?>