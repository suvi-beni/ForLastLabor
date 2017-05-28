import xml.etree.ElementTree as ET


def main():

    modul = ET.parse("C:\\Users\\Suvi\\Desktop\\data\\structure\\digana.xml")

    digana = ET.parse("C:\\Users\\Suvi\\Desktop\\data\\input\\digana_compressed.xml")

    # for element in digana.getroot().iter():
    #     element.tag = element.tag.split("}")[-1]
    #     print(element)

    lookUpTable = [[], []]
    path = ""

    fillLookUpTable(modul.getroot(), lookUpTable, path)

    return


def fillLookUpTable(modul, lookUpTable, p_path):

    for element in modul:
        if element.tag in ["leaf", "leaf-list", "container", "list", "choice", "group"]:
            print(element.tag, element.attrib)

            if "name" in element.attrib and element.tag not in ["choice", "group"]:
                path = p_path + "/" + element.attrib["name"].split(":")[-1]
            else:
                path = p_path

            if element.tag == "choice" and element.attrib.get("name"):
                b_choice = True
                for child in element:
                    if child.tag != "group" or (not child.attrib.get("name")):
                        b_choice = b_choice and False
            else:
                b_choice = False

            if element.tag in ["leaf", "leaf-list"] or b_choice:
                if b_choice:
                    lookUpTable[0].append(path + "/" + element.attrib["name"].split(":")[-1])
                else:
                    lookUpTable[0].append(path)

            if len(element) != 0:
                fillLookUpTable(element, lookUpTable, path)

    return


if __name__ == '__main__':
    main()
