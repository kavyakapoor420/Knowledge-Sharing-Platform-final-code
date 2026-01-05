

//it will run only on first render -> empty dependecy array passed

import React, { useState ,useEffect} from "react"

function TimerComponent(){

     const [seconds,setSeconds]=useState(0)

     useEffect(()=>{
            const intervalId=setInterval(()=>{

                console.log('setInterval executed')
                setSeconds(prevSec=>prevSec+1)
            },1000)

            return ()=>{
                console.log('time to stop')
                clearInterval(intervalId) // on component unmount 
            }
     },[])

    return(
        <>
             <h1>Second {seconds}</h1>
        </>
    )
}


export default TimerComponent