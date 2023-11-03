from setuptools import find_packages, setup

package_name = 'learn_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='darm',
    maintainer_email='darm@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "py_test_node = learn_py_pkg.py_test_node:main",
            "py_test_node_oop = learn_py_pkg.py_test_node_oop:main"
        ],
    },
)
