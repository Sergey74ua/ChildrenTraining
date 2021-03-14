using UnityEngine;
using UnityEngine.EventSystems;

public class MoveCube : MonoBehaviour, IPointerClickHandler
{
    [SerializeField]
    public GameObject MyCube;
    float delta;

    void Update()
    {
        delta = Input.GetAxis("Horizontal") * 50;

        MyCube.transform.position = new Vector3(100 + delta, 20, 100);

        //Куб - красный
        if (Input.GetKeyUp(KeyCode.R))
            MyCube.GetComponent<Renderer>().material.color = Color.red;
        //Куб - зеленый
        else if (Input.GetKeyUp(KeyCode.G))
            MyCube.GetComponent<Renderer>().material.color = Color.green;
        //Куб - зеленый
        else if (Input.GetKeyUp(KeyCode.B))
            MyCube.GetComponent<Renderer>().material.color = Color.blue;

        //Куб - скрываем
        if (Input.GetKeyUp(KeyCode.Z) && MyCube != null)
            MyCube.SetActive(false);

        //Куб - показываем
        if (Input.GetKeyUp(KeyCode.X) && MyCube != null)
            MyCube.SetActive(true);

        //Куб - удаляем
        if (Input.GetKeyUp(KeyCode.Escape))
            Destroy(MyCube);

        //Куб - вращяем стрелочками
        if (Input.GetKeyUp(KeyCode.UpArrow))
            MyCube.transform.Translate(Vector3.forward * 50 * Time.deltaTime);
        if (Input.GetKeyUp(KeyCode.DownArrow))
            MyCube.transform.Translate(-Vector3.forward * 50 * Time.deltaTime);
        if (Input.GetKeyUp(KeyCode.LeftArrow))
            MyCube.transform.Rotate(Vector3.up, -50 * Time.deltaTime);
        if (Input.GetKeyUp(KeyCode.RightArrow))
            MyCube.transform.Rotate(Vector3.up, 50 * Time.deltaTime);
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        Color color = new Color(Random.Range(0.0f, 1.0f), Random.Range(0.0f, 1.0f), Random.Range(0.0f, 1.0f));
        gameObject.GetComponent<Renderer>().material.color = color;
    }
}