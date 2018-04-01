using System;
using System.Collections.Generic;
using System.Text;

namespace JsonSampleCsharp
{
    class Sample
    {
        public string TestString { get; set; }
        public string[] TestArrayString { get; set; }
        public byte[] TestArrayBytes { get; set; }
        public Inner Inner { get; set; }
        public List<Inner> InnerList { get; set; }
    }

    class Inner
    {
        public double TestDouble { get; set; }
        public int TestInt { get; set; }
        public bool TestBool { get; set; }
    }
}
