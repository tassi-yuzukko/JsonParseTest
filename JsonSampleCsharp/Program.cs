using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;

namespace JsonSampleCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            var rand = new Random();

            var inner = new Inner
            {
                TestBool = true,
                TestDouble = 0.0001,
                TestInt = 9999,
            };

            var innerList = new List<Inner>();
            for (int i = 0; i < 20; i++)
            {
                innerList.Add(new Inner
                {
                    TestBool = (i % 2 == 0),
                    TestInt = rand.Next(),
                    TestDouble = rand.NextDouble(),
                });
            }

            var sample = new Sample
            {
                TestString = "this is test !!",
                TestArrayBytes = new byte[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 },
                TestArrayString = new string[] { "I", "am", "tashima" },
                Inner = inner,
                InnerList = innerList,
            };

            var setting = new JsonSerializerSettings { MissingMemberHandling = MissingMemberHandling.Ignore, NullValueHandling = NullValueHandling.Ignore, Formatting = Formatting.Indented, ContractResolver = new CamelCasePropertyNamesContractResolver() };
            var str = JsonConvert.SerializeObject(sample, setting);

            File.WriteAllText("Sample.json", str, Encoding.UTF8);
        }
    }
}
