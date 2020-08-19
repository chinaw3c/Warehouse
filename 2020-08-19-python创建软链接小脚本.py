import os,shutil

def get_framework(path = "./"):
    """
    接受path获取path目录下的所有.framework文件，返回一个文件名列表

    :path: 目标地址
    :returns: 文件名列表

    """
    filelist = os.listdir(path)
    frameworks = []

    for filename in filelist:
        # 筛选出文件后缀名为framework的文件
        if filename.split(".")[-1] == "framework":
            dirname = filename.split(".")[0]
            frameworks.append(dirname)

    return frameworks

def main():
    """TODO: Docstring for main.
    :returns: TODO

    """
    ln_list = get_framework()

    for ln in ln_list:
        # 执行系统命令创建软链接
        os.system("ln -s {}.framework ../include/{}".format(ln, ln))
        print("创建{}软链接成功".format(ln))
        

if __name__ == "__main__":
    main()
