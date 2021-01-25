<?php
//Headers
header('Access-Control-Allow-Origin: *');
header('Content-Type: application/json');

include_once '../../config/Database.php';
include_once '../../models/Service.php';
include_once '../authentication/auth2.php';
//here we authenticate and maake sure that the key that the user sends is correct. if so the rest of the code is excecuted.
$API="";
if(isset($_REQUEST['API']))
	$API = $_REQUEST['API'];
if(verify($API)){
//Instantiate DB & connect
$database = new Database();
$db = $database->connect();

//Instantiate service object
$service = new Service($db);
//we check so that the userID is included. 
if(isset($_REQUEST['userID'])){
    $service->userID = $_REQUEST['userID'];
    $result = $service->read_service_fuckyeah();


    //Get row count
    $num = $result->rowCount();
    
    //Check if any service
    if($num > 0){
        //Service array
        $service_arr = array();
        $service_arr['data'] = array();
    
        while($row = $result->fetch(PDO::FETCH_ASSOC)){
            extract($row);
    
            $service_item = array(
                'userID' => $userID,
                'serviceID' => $serviceID,
                'serviceType' => $serviceType
            );
    
            //Push to "data"
            array_push($service_arr['data'], $service_item);
        }
        //Turn to JSON and output
        echo json_encode($service_arr);
    }else{
        echo json_encode(array('message'=>'Wrong input'));
    }

}else{
//No service
echo json_encode(
    array('message' => 'No Services Found')
);
}
}else{
    echo FALSE;
}

?>