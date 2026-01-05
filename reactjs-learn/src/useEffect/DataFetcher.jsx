import { useEffect, useState } from "react"

//it will run only on 1st render  -> empty dependecy array 

function DataFetcher(){

    const [data,setData]=useState([])
    const [loading,setLoading]=useState(true)

    useEffect(()=>{
        fetch('https://jsonplaceholder.typicode.com/posts')
         .then(res=>res.json())
         .then(data=>{
            setData(data)
            setLoading(false)
         })
    },[])

    return(
        <>
            {
                loading ? (
                    <h1> Loadding ......</h1>
                )       :(
                    <ul>
                        {
                            data.map(post=>(
                                <li key={post.id}>
                                    {post.title}
                                </li>
                            ))
                        }
                    </ul>
                )
            }
        </>
    )
}

export default DataFetcher