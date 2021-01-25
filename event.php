<?php

Class Event{
    //DB Stuff
    private $conn;
    private $table = 'event';

    //Event Properties
    public $startDate;
    public $eventTitle;
    public $description;
    public $endDate;
    public $userID;
    public $inviteID;
    
    
    /**
     * __construct
     *
     * @param  mixed $db
     * this function expects a database object that has been created from the database class.
     * @return void
     */
    public function __construct($db){
        $this->conn = $db;
    }
    
    /**
     * read_event
     * this function gets all the events from the database and returns them. 
     * @return string
     * returns all the events in the database
     */
    public function read_event(){
        //Create query
        $query = 'SELECT * FROM event WHERE userID=:userID';
        //Preparing statement
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':userID', $this->userID);
        
        //Executing query
        $stmt->execute();
  
        return $stmt;
        
    }
        
    /**
     * invite_event
     * this function returns the events based on the invite ID
     * @return string
     */
    public function invite_event(){
        $query = 'SELECT * FROM event WHERE inviteID = :userID';
        //Preparing statement
        $stmt = $this->conn->prepare($query);
        //Executing query
        //Binding pageID
        $stmt->bindParam(':userID', $this->userID);
        $stmt->execute();

        return $stmt;
    }
	        
        /**
         * invite_user_event
         * this function invites a user to an event. it returns true if successful and false if it fails.
         * @return boolean
         */
        public function invite_user_event(){
            //Update query
            $query = 'UPDATE ' . $this->table . '
            SET
                inviteID = :inviteID
            WHERE
                eventID = :eventID';
    
                //Preparing statement
                $stmt = $this->conn->prepare($query);
    
                //Clean data
                $this->inviteID =htmlspecialchars(strip_tags($this->inviteID));
    
                //Bind data
                $stmt->bindParam(':inviteID', $this->inviteID);
                $stmt->bindParam(':eventID', $this->eventID);
                
    
                //Executing query
                if($stmt->execute()){
                    return true;
                }
    
                //Print error
                printf("Error: %s.\n", $stmt->error);
                return false;
        }
    
    /**
     * admin_event
     * this function returns all the events if you are an admin.
     * @return string
     */
    public function admin_event(){
         //Create query
        $query = 'SELECT * FROM event, privilege WHERE event.eventID = eventID AND privilege.admin = 1';
        //Preparing statement
        $stmt = $this->conn->prepare($query);
        //Executing query
        $stmt->execute();

        return $stmt;
    }
    
        
    /**
     * read_single_event
     *this function gets a single event from the database and returns it
     * @return string
     */
    public function read_single_event(){
        $query = 'SELECT * FROM event WHERE eventID = :eventID';
        //Preparing statement
        $stmt = $this->conn->prepare($query);

        //Binding pageID
        $stmt->bindParam(':eventID', $this->eventID);
       

        //Executing query
        $stmt->execute();

        $row = $stmt->fetch(PDO::FETCH_ASSOC);

        //Setting properties
        $this->eventID = $row['eventID'];
        $this->startDate = $row['startDate'];
        $this->eventTitle = $row['eventTitle'];
        $this->description = $row['description'];
        $this->endDate = $row['endDate'];
        $this->userID = $row['userID'];
        $this->inviteID = $row['inviteID'];
        return $stmt;
    }

    //Create Event    
    /**
     * create_event
     *this function createns an event in the database. it returns true if successful.
     * @return boolean
     */
    public function create_event(){
        //Create query
        $query = 'INSERT INTO ' . $this->table . '
        SET
            startDate = :startDate,
            eventTitle = :eventTitle,
            description = :description,
            endDate = :endDate,
            userID = :userID,
            inviteID = :inviteID';

            //Preparing statement
            $stmt = $this->conn->prepare($query);

            //Clean data
            $this->startDate =htmlspecialchars(strip_tags($this->startDate));
            $this->eventTitle =htmlspecialchars(strip_tags($this->eventTitle));
            $this->description =htmlspecialchars(strip_tags($this->description));
            $this->endDate =htmlspecialchars(strip_tags($this->endDate));
            $this->userID =htmlspecialchars(strip_tags($this->userID));
            $this->inviteID =htmlspecialchars(strip_tags($this->inviteID));
            

            //Bind data
            $stmt->bindParam(':startDate', $this->startDate);
            $stmt->bindParam(':eventTitle', $this->eventTitle);
            $stmt->bindParam(':description', $this->description);
            $stmt->bindParam(':endDate', $this->endDate);
            $stmt->bindParam(':userID', $this->userID);
            $stmt->bindParam(':inviteID', $this->inviteID);
           

            //Executing query
            if($stmt->execute()){
                return true;
            }

            //Print error
            printf("Error: %s.\n", $stmt->error);
            return false;
    }
        
        /**
         * update_event
         * this function takes an eventID and edits the diferent propertys of an  event. example title. returns true if successful
         * @return bool
         */
        public function update_event(){
            //Update query
            $query = 'UPDATE ' . $this->table . '
            SET
                startDate = :startDate,
                eventTitle = :eventTitle,
                description = :description,
                endDate = :endDate,
                userID = :userID,
                inviteID = :inviteID
            WHERE
                eventID = :eventID';
    
                //Preparing statement
                $stmt = $this->conn->prepare($query);
    
                //Clean data
                $this->startDate =htmlspecialchars(strip_tags($this->startDate));
                $this->eventTitle =htmlspecialchars(strip_tags($this->eventTitle));
                $this->description =htmlspecialchars(strip_tags($this->description));
                $this->endDate =htmlspecialchars(strip_tags($this->endDate));
                $this->userID =htmlspecialchars(strip_tags($this->userID));
                $this->inviteID =htmlspecialchars(strip_tags($this->inviteID));
    
                //Bind data
                $stmt->bindParam(':startDate', $this->startDate);
                $stmt->bindParam(':eventTitle', $this->eventTitle);
                $stmt->bindParam(':description', $this->description);
                $stmt->bindParam(':endDate', $this->endDate);
                $stmt->bindParam(':userID', $this->userID);
                $stmt->bindParam(':inviteID', $this->inviteID);
                $stmt->bindParam(':eventID', $this->eventID);
                
    
                //Executing query
                if($stmt->execute()){
                    return true;
                }
    
                //Print error
                printf("Error: %s.\n", $stmt->error);
                return false;
        }

        
        /**
         * delete_event
         *this function removes an event from the database. returns true if successful
         * @return void
         */
        public function delete_event(){
            //Creating query
            $query = 'DELETE FROM '. $this->table .'
            WHERE eventID = :eventID';

            //Preparing statement
            $stmt = $this->conn->prepare($query);

            //Clean data
            $this->eventID =htmlspecialchars(strip_tags($this->eventID));

            //Bind data
            $stmt->bindParam(':eventID', $this->eventID);

            //Executing query
            if($stmt->execute()){
                return true;
            }
            
            //Print error
            printf("Error: %s.\n", $stmt->error);
            return false;
        }

}

Class Event_history{
    //DB Stuff
    private $conn;
    private $table = 'event';

    //Event Properties
    public $eventID;
    public $startDate;
    public $endDate;
    public $eventTitle;
    public $description;

        
    /**
     * __construct
     *
     * @param  mixed $db
     * the constructor expects a database object
     * @return void
     */
    public function __construct($db){
        $this->conn = $db;
    }
    
    /**
     * read_event_history
     *this function returns all events in the database.
     * @return string
     */
    public function read_event_history(){
        //Create query
        $query = 'SELECT * FROM event';
        //Preparing statement
        $stmt = $this->conn->prepare($query);
        //Executing query
        $stmt->execute();

        return $stmt;
    }

}

?>